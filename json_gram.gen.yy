%include {
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "json.h"
#include "json_private.h"
}

%left SR_COMMA.

%token_type { yyval }
%extra_argument { yycontext* ctx }

%syntax_error { fprintf(stderr, "syntax error\n"); }
%parse_failure { fprintf(stderr,"unrecoverable parser error\n"); }
%parse_accept { fprintf(stderr,"parsing complete!\n"); }


/* grammar start --------------------------------------------------------------------- */
%type primitive			{ json_node* }
%type list				{ json_node* }
%type list_content		{ json_node* }
%type object			{ json_node* }
%type object_content	{ json_node* }

%start_symbol json
json ::= primitive(A).	{ ctx->root = A; }
json ::= list(A).		{ ctx->root = A; }
json ::= object(A).		{ ctx->root = A; }

primitive(A) ::= SR_NULL.			{ A = json_node_create(JSONTYPE_NULL); }
primitive(A) ::= SR_BOOL(V).		{ A = json_node_create(JSONTYPE_BOOLEAN), A->val.as_boolean = V.val.as_boolean; }
primitive(A) ::= SR_NUM_INT(V).		{ A = json_node_create(JSONTYPE_NUMBER), A->val.as_number = V.val.as_number; }
primitive(A) ::= SR_NUM_FLOAT(V).	{ A = json_node_create(JSONTYPE_NUMBER), A->val.as_number  = V.val.as_number; }
primitive(A) ::= SR_STRING(V).		{ A = json_node_create(JSONTYPE_STRING), A->val.as_string = V.val.as_string; }

list(A) ::= SR_LBRACKET SR_RBRACKET.					{ A = json_node_create(JSONTYPE_LIST); }
list(A) ::= SR_LBRACKET list_content(B) SR_RBRACKET.	{ A = B; }
list_content(A) ::= primitive(B).						{ A = json_node_create(JSONTYPE_LIST), json_node_list_add(A, B); }
list_content(A) ::= list(B).							{ A = json_node_create(JSONTYPE_LIST), json_node_list_add(A, B); }
list_content(A) ::= object(B).							{ A = json_node_create(JSONTYPE_LIST), json_node_list_add(A, B); }
/* list_content ::= list_content(A) SR_COMMA list_content(B).	{ json_node_list_merge(A, B, true); } // looks quite fancy. but decreases performance */
list_content ::= list_content(A) SR_COMMA primitive(B).	{ json_node_list_add(A, B); }
list_content ::= list_content(A) SR_COMMA list(B).		{ json_node_list_add(A, B); }
list_content ::= list_content(A) SR_COMMA object(B).	{ json_node_list_add(A, B); }

object(A) ::= SR_LBRACE SR_RBRACE.									{ A = json_node_create(JSONTYPE_OBJECT); }
object(A) ::= SR_LBRACE object_content(B) SR_RBRACE.				{ A = B; }
object_content(A) ::= SR_STRING(V) SR_COLON primitive(B).			{ A = json_node_create(JSONTYPE_OBJECT), json_node_object_put(A, V.val.as_string, B); }
object_content(A) ::= SR_STRING(V) SR_COLON list(B).				{ A = json_node_create(JSONTYPE_OBJECT), json_node_object_put(A, V.val.as_string, B); }
object_content(A) ::= SR_STRING(V) SR_COLON object(B).				{ A = json_node_create(JSONTYPE_OBJECT), json_node_object_put(A, V.val.as_string, B); }
/* object_content ::= object_content(A) SR_COMMA object_content(B).	{ json_node_object_merge(A, B, true); } // looks quite fancy. but decreases performance */
object_content ::= object_content(A) SR_COMMA SR_STRING(V) SR_COLON primitive(B).{ json_node_object_put(A, V.val.as_string, B); }
object_content ::= object_content(A) SR_COMMA SR_STRING(V) SR_COLON list(B).	{ json_node_object_put(A, V.val.as_string, B); }
object_content ::= object_content(A) SR_COMMA SR_STRING(V) SR_COLON object(B).	{ json_node_object_put(A, V.val.as_string, B); }

