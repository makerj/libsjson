#ifndef __JSON_H__
#define __JSON_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libs/ds/vec.h"
#include "libs/ds/hmap.h"

typedef enum _json_type {
	JSONTYPE__INVALID,

	JSONTYPE_NULL,
	JSONTYPE_BOOLEAN,
	JSONTYPE_NUMBER,
	JSONTYPE_STRING,
	JSONTYPE_LIST,
	JSONTYPE_OBJECT,
} json_type;

typedef struct _json_node {
	int type;
	union {
		bool as_boolean;
		double as_number;
		char* as_string;
		struct vec* as_list;
		struct hmap* as_object;
	} val;
} json_node;

json_node* json_node_create(json_type type);
void json_node_destroy(json_node* node);
json_node* json_node_load(FILE* json);
void json_node_dump(json_node* node, FILE* stream);

void json_node_list_add(json_node* a_list, json_node* node);
void json_node_object_put(json_node* a_object, char* a_key, json_node* node);

#endif
