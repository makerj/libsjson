#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "json_private.h"
#include "json_gram.gen.h"

json_node* json_node_create(json_type type) {
	json_node* node = calloc(1, sizeof(json_node));
	node->type = type;

	return node;
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
			// TODO destroy each children + list destroy
			break;
		case JSONTYPE_OBJECT:
			// TODO destroy each children + map destroy
			break;
	}

	memset(node, 0, sizeof(json_node)), free(node);
}

void json_node_list_add(json_node* a_list, json_node* node) {
	a_list->val.as_list.nodes[a_list->val.as_list.nodes_size++] = node;
}

void json_node_list_merge(json_node* lhs, json_node* rhs, bool destroy_rhs) {
	for(size_t i = 0; i < rhs->val.as_list.nodes_size; ++i) {
		json_node_list_add(lhs, rhs->val.as_list.nodes[i]);
	}
}

void json_node_map_put(json_node* a_object, char* a_key, json_node* node) {
	/* char* key = strdup(a_key); */
	a_object->val.as_list.nodes[a_object->val.as_list.nodes_size++] = node;
}

void json_node_map_merge(json_node* lhs, json_node* rhs, bool destroy_rhs) {
	for(size_t i = 0; i < rhs->val.as_list.nodes_size; ++i) {
		json_node_list_add(lhs, rhs->val.as_list.nodes[i]);
	}
}

void json_node_dump(json_node* node) {
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
			putchar('[');
			for(size_t i = 0; i < node->val.as_list.nodes_size; ++i) {
				json_node_dump(node->val.as_list.nodes[i]);
				if(i + 1 < node->val.as_list.nodes_size)
					putchar(',');
			}
			putchar(']');
			break;
		case JSONTYPE_OBJECT:
			putchar('{');
			for(size_t i = 0; i < node->val.as_list.nodes_size; ++i) {
				printf("\"KEYSTR_GOES_HERE\":"); // TODO key print
				json_node_dump(node->val.as_list.nodes[i]);
				if(i + 1 < node->val.as_list.nodes_size)
					putchar(',');
			}
			putchar('}');
			break;
	}
}

int main(int argc, char** argv) {
	/* char buf[] = */
	/* 	"\\\" 1234 0x1234 0b10 0100 \"hello \\\" world\" 'error123' 22 true false null" */
	/* 	"[1,2,3,4,\"hello\",\"hello \\\" \\\" again\",null,true,false,{}]" */
	/* 	"{ \"key\": \"value\", \"key2\": null }"; */
	/* char buf[] = "[1234,5678,[123],{\"a\":1,\"b\":{\"aa\":\"vv\"}}]"; */
	/* char buf[] = "[1234,5678,null,true,false,[123]]"; */
	char buf[] = "[12.34,1234,1234,null,true,false,\"hello\",[],[1,2,3],{\"a\": 1, \"b\": \"val\"}]";
	FILE* json = fmemopen(buf, sizeof(buf), "r");

	void* scanner = scanner_create(json);
	void* parser = ParseAlloc(malloc);
	ParseTrace(stdout, "parser-tracer: ");
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
	assert(token_type != -2);
	Parse(parser, 0, val, &parser_ctx);

	scanner_destroy(scanner);
	fclose(json);

	ParseFree(parser, free);

	json_node_dump(parser_ctx.root);

	return 0;
}
