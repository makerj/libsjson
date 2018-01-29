%include {
#include <assert.h>
#include "json_private.h"
}

%left SR_COMMA.

%token_type { yynode }
%extra_argument { yycontext* ctx }

%syntax_error { fprintf(stderr, "syntax error\n"); }
%parse_failure { fprintf(stderr,"unrecoverable parser error\n"); }
%parse_accept { fprintf(stderr,"parsing complete!\n"); }


/* grammar start --------------------------------------------------------------------- */
%start_symbol json

json ::= primitive(A). { ctx->root = A; }
json ::= list(A). { ctx->root = A; }
json ::= object(A). { ctx->root = A; }

primitive(A) ::= SR_NUMBER(B).		{ A = B; }
primitive(A) ::= SR_BOOL(B).		{ A = B; }
primitive(A) ::= SR_STRING(B).		{ A = B; }
primitive(A) ::= SR_NULL(B).		{ A = B; }

list ::= SR_LBRACKET SR_RBRACKET.
list ::= SR_LBRACKET list_content SR_RBRACKET.
list_content ::= primitive.
list_content ::= list.
list_content ::= object.
list_content ::= list_content SR_COMMA list_content.

object ::= SR_LBRACE SR_RBRACE.
object ::= SR_LBRACE object_content SR_RBRACE.
object_content ::= SR_STRING SR_COLON primitive.
object_content ::= SR_STRING SR_COLON list.
object_content ::= SR_STRING SR_COLON object.
object_content ::= object_content SR_COMMA object_content.

