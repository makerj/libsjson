#ifndef __JSON_PRIVATE_H__
#define __JSON_PRIVATE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "json.h"

// Internal node representation ---------------------------------------------------------
typedef struct {
	union {
		bool as_boolean;
		double as_number;
		char* as_string;
	} val;
} yyval;

typedef struct {
	json_node* root;
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
extern void Parse(void* parser, int token, yyval val, yycontext* ctx);
extern void ParseFree(void *parser, void (*freeProc)(void*));
extern void ParseTrace(FILE* output_stream, char* tag);

#endif
