#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "json_private.h"
#include "json_gram.gen.h"

json_node* json_node_create(json_type type) {
	json_node* node = (json_node*)calloc(1, sizeof(json_node));
	node->type = type;
	switch(node->type) {
		case JSONTYPE_LIST:
			node->val.as_list = vec_create();
			break;
		case JSONTYPE_OBJECT:
			node->val.as_object = hmap_create();
			break;
	}

	return node;
}

static void json_node_destroy_typeless(void* a_node) {
	json_node_destroy((json_node*)a_node);
}

void json_node_destroy(json_node* node) {
	switch(node->type) {
		case JSONTYPE_NULL:
		case JSONTYPE_BOOLEAN:
		case JSONTYPE_NUMBER:
			break;
		case JSONTYPE_STRING:
			free(node->val.as_string);
			break;
		case JSONTYPE_LIST:
			vec_destroy(node->val.as_list, json_node_destroy_typeless);
			break;
		case JSONTYPE_OBJECT:
			hmap_destroy(node->val.as_object, free, json_node_destroy_typeless);
			break;
	}

	memset(node, 0, sizeof(json_node)), free(node);
}

void json_node_list_add(json_node* a_list, json_node* node) {
	vec_push_back(a_list->val.as_list, node);
}

void json_node_object_put(json_node* a_object, char* a_key, json_node* node) {
	hmap_put(a_object->val.as_object, a_key, node);
}

json_node* json_node_load(FILE* json) {
	void* scanner = scanner_create(json);
	void* parser = ParseAlloc(malloc);
#ifndef NDBUG
	ParseTrace(stdout, "parser-tracer: ");
#endif
	yyval val = {};
	yycontext parser_ctx = {};

	int token_type;
	char* token_raw;
	size_t token_rawsize;
	while((token_type = scanner_scan(scanner, &token_raw, &token_rawsize)) >= 0) {
		if(token_type == SERR_BADCHAR)
			continue;

		char buf[token_rawsize + 1];
		strncpy(buf, token_raw, token_rawsize);
		buf[token_rawsize] = '\0';

		// parse primitive value
		printf("token_type[%d]\ttoken_val[%s]\n", token_type, buf);
		switch(token_type) {
			case SR_NUM_INT:
				val.val.as_number = (double)strtoul(buf, NULL, 0);
				break;
			case SR_NUM_FLOAT:
				val.val.as_number = (double)atof(buf);
				break;
			case SR_STRING:
				val.val.as_string = strdup(buf);
				break;
			case SR_BOOL:
				val.val.as_boolean = strcasecmp(buf, "true") == 0;
				break;
		}
		Parse(parser, token_type, val, &parser_ctx);
	}
	if(token_type <= SERR_FATAL)
		json_node_destroy(parser_ctx.root), parser_ctx.root = NULL;
	else
		Parse(parser, 0, val, &parser_ctx);

	scanner_destroy(scanner);
	ParseFree(parser, free);

	return parser_ctx.root;
}

void json_node_dump(json_node* node) {
	size_t length;

	switch(node->type) {
		case JSONTYPE_NULL:
			printf("null");
			break;
		case JSONTYPE_BOOLEAN:
			printf("%s", node->val.as_boolean ? "true" : "false");
			break;
		case JSONTYPE_NUMBER:
			if(node->val.as_number == (int64_t)node->val.as_number)
				printf("%ld", (int64_t)node->val.as_number);
			else
				printf("%lf", node->val.as_number);
			break;
		case JSONTYPE_STRING:
			printf("\"%s\"", node->val.as_string);
			break;
		case JSONTYPE_LIST:
			length = node->val.as_list->length;
			putchar('[');
			for(size_t i = 0; i < length; ++i) {
				json_node_dump((json_node*)node->val.as_list->items[i]);
				if(i + 1 < length)
					putchar(',');
			}
			putchar(']');
			break;
		case JSONTYPE_OBJECT:
			putchar('{');
			for(size_t i = 0, count = 0; i < node->val.as_object->capacity; ++i) {
				struct vec* bucket = node->val.as_object->buckets[i];
				if(!bucket)
					continue;

				for(size_t j = 0; j < bucket->length; ++j) {
					struct hmap_entry* e = (struct hmap_entry*)bucket->items[j];
					printf("\"%s\":", e->key);
					json_node_dump((json_node*)e->value);
					if(count + 1 < node->val.as_object->length)
						putchar(',');

					count += 1;
				}
			}
			putchar('}');
			break;
	}
}

int main(int argc, char** argv) {
	char buf[] = "[12.34,1234,1234,null,true,false,\"hi\",\"a \\\"b c\",[],[1,2,3],{\"a\": 1, \"b\": \"val\"}]";
	FILE* json = fmemopen(buf, sizeof(buf), "r");

	json_node* root = json_node_load(json);
	json_node_dump(root);
	json_node_destroy(root);

	return 0;
}
