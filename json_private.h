#ifndef __JSON_PRIVATE_H__
#define __JSON_PRIVATE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Internal node representation ---------------------------------------------------------
#define YYNODE_VALTYPE_NUMBER		1
#define YYNODE_VALTYPE_BOOLEAN		2
#define YYNODE_VALTYPE_STRING		3
#define YYNODE_VALTYPE_NULL			4
typedef struct {
	int val_type;
	union {
		bool as_boolean;
		double as_number;
		char* as_string;
	} val;
} yynode;

typedef struct {
	yynode root;
} yycontext;

// Scanner Result -----------------------------------------------------------------------
#define SERR_NOMEM		-2
#define SERR_EOF		-1
#define SERR_BADCHAR	0

// scanner & grammar api ----------------------------------------------------------------
extern void* scanner_create(FILE* stream);
extern void scanner_destroy(void* a_scanner);
extern int scanner_scan(void* a_scanner, char** out, size_t* outlen);

extern void* ParseAlloc(void*(*mallocProc)(size_t size));
extern void Parse(void* parser , int token, yynode token_val_as_node, yycontext* ctx);
extern void ParseFree(void *parser, void (*freeProc)(void*));
extern void ParseTrace(FILE* output_stream, char* tag);

#endif
