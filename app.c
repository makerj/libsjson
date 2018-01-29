#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "json_private.h"
#include "json_gram.gen.h"

int main(int argc, char** argv) {
	/* char buf[] = */
	/* 	"\\\" 1234 0x1234 0b10 0100 \"hello \\\" world\" 'error123' 22 true false null" */
	/* 	"[1,2,3,4,\"hello\",\"hello \\\" \\\" again\",null,true,false,{}]" */
	/* 	"{ \"key\": \"value\", \"key2\": null }"; */
	char buf[] = "[1234,5678,[123],{\"a\":1,\"b\":{\"aa\":\"vv\"}}]";
	FILE* json = fmemopen(buf, sizeof(buf), "r");

	void* scanner = scanner_create(json);
	void* parser = ParseAlloc(malloc);
	ParseTrace(stdout, "parser-tracer: ");
	yynode node_val = {};
	yycontext parser_ctx = {};

	int token;
	char* token_val;
	size_t token_valsize;
	while((token = scanner_scan(scanner, &token_val, &token_valsize)) >= 0) {
		if(token == SERR_BADCHAR)
			continue;

		printf("token[%d]\ttoken_val[%.*s]\n", token, (int)token_valsize, token_val);
		switch(token) {
			case SR_NUMBER:
				node_val.val_type = YYNODE_VALTYPE_NUMBER;
				node_val.val.as_number = (double)strtoul(token_val, NULL, 0);
				break;
			case SR_STRING:
				node_val.val_type = YYNODE_VALTYPE_STRING;
				node_val.val.as_string = strndup(token_val, token_valsize);
				break;
		}
		Parse(parser, token, node_val, &parser_ctx);
	}
	assert(token != -2);
	Parse(parser, 0, node_val, &parser_ctx);

	scanner_destroy(scanner);
	fclose(json);

	ParseFree(parser, free);

	return 0;
}
