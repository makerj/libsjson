#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "json_private.h"
#include "json_gram.gen.h"

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

/*!max:re2c*/
#ifndef YYMAXFILL
#define YYMAXFILL 1
#endif

#define SCANNER_BUFSIZ 32768
struct scanner {
	FILE* stream;
	char buf[SCANNER_BUFSIZ + YYMAXFILL];
	char* cur;
	char* mark;
	char* lim;
};

void* scanner_create(FILE* stream) {
	struct scanner* scanner = calloc(1, sizeof(struct scanner));
	if(!scanner)
		return NULL;

	size_t nread = fread(scanner->buf, 1, SCANNER_BUFSIZ, stream);
	if(nread == 0) {
		free(scanner);
		return NULL;
	}

	scanner->stream = stream;
	scanner->cur = scanner->buf;
	scanner->mark = scanner->buf;
	scanner->lim = scanner->buf + nread;

	return scanner;
}

void scanner_destroy(void* a_scanner) {
	free(a_scanner);
}

static bool scanner_fill(struct scanner* scanner, ssize_t amount) {
	ssize_t len = scanner->lim - scanner->cur;
	ssize_t cap = SCANNER_BUFSIZ - len;

	/* printf("fill: val[%c] len[%d] cap[%d] amount[%d] cur[%p] lim[%p]\n", */
	/* 		*scanner->cur, (int)len, (int)cap, (int)amount, scanner->cur, scanner->lim); */

	if(unlikely(len < 0) || unlikely(amount >= cap))
		return false;

	// left shifting
	memmove(scanner->buf, scanner->cur, len);

	// filling
	ssize_t nread = fread(scanner->buf + len, 1, cap, scanner->stream);
	if(nread == 0 && ferror(scanner->stream))
		return false;

	// resetting
	scanner->mark -= scanner->cur - scanner->buf;
	scanner->cur = scanner->buf;
	scanner->lim = scanner->buf + len + nread;
	memset(scanner->lim, 0, YYMAXFILL);

	return true;
}

int scanner_scan(void* a_scanner, char** out, size_t* outsize) {
	struct scanner* scanner = (struct scanner*)a_scanner;

	#define RET(SR) *outsize = 0; return (SR);
	#define RETV(SR) *out = ts, *outsize = te - ts; return (SR);

	/*!stags:re2c format = 'char* @@;';*/
	char *ts = NULL, *te = NULL;
start:
	/*!re2c
		re2c:define:YYCTYPE = char;
		re2c:define:YYCURSOR = scanner->cur;
		re2c:define:YYMARKER = scanner->mark;
		re2c:define:YYLIMIT = scanner->lim;
		re2c:define:YYFILL = "if(!scanner_fill(scanner, @@)) return SERR_NOMEM;";
		re2c:define:YYFILL:naked = 1;

		end = "\x00";
		white = [ \t\r\n];
		colon = [:];
		comma = [,];
		lbracket = '[';
		rbracket = ']';
		lbrace = '{';
		rbrace = '}';
		esc_dquote = '\\"';

		num_bin = '0b'[01]+;
		num_oct = '0'[1-7][0-7]*;
		num_dec = [1-9][0-9]*;
		num_hex = '0x'[0-9a-fA-F];
		num_int = @ts (num_bin | num_oct | num_dec | num_hex ) @te;
		num_float = @ts [0-9]+ "." [0-9]* @te;
		str = ["] @ts (esc_dquote | [^"])* @te ["];
		null = 'null';
		bool_true = 'true';
		bool_false = 'false';

		*			{ RET(SERR_BADCHAR); }
		end			{ RET(SERR_EOF); }

		white		{ goto start; }
		num_int		{ RETV(SR_NUM_INT); }
		num_float	{ RETV(SR_NUM_FLOAT); }
		str			{ RETV(SR_STRING); }
		null		{ RET(SR_NULL); }
		bool_true	{ RET(SR_BOOL); }
		bool_false	{ RET(SR_BOOL); }
		colon		{ RET(SR_COLON); }
		comma		{ RET(SR_COMMA); }
		lbracket	{ RET(SR_LBRACKET); }
		rbracket	{ RET(SR_RBRACKET); }
		lbrace		{ RET(SR_LBRACE); }
		rbrace		{ RET(SR_RBRACE); }
	 */

	return -1;
}
