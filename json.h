#ifndef __JSON_H__
#define __JSON_H__

#include <stdbool.h>
#include <stdlib.h>
/* #include "hashmap.h" */

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
		struct {
			struct _json_node* nodes[50];
			size_t nodes_size;
		} as_list; // TODO Use linkedlist
		// struct as_object // TODO Use hashmap<char*, struct json_node*>
	} val;
} json_node;

json_node* json_node_create(json_type type);
void json_node_destroy(json_node* node);
void json_node_dump(json_node* node);

void json_node_list_add(json_node* a_list, json_node* node);
void json_node_list_merge(json_node* lhs, json_node* rhs, bool destroy_rhs);

void json_node_map_put(json_node* a_object, char* a_key, json_node* node);
void json_node_map_merge(json_node* lhs, json_node* rhs, bool destroy_rhs);

#endif
