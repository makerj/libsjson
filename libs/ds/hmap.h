#ifndef __HMAP_H__
#define __HMAP_H__

#include "vec.h"

struct hmap {
	struct vec** buckets;
	size_t length;
	size_t capacity;
};

struct hmap_entry {
	char* key;
	void* value;
};

struct hmap* hmap_create();
void hmap_destroy(struct hmap* self, void(*key_free)(void*), void(*value_free)(void*));
int hmap_put(struct hmap* self, char* key, void* value);
void* hmap_get(struct hmap* self, char* key);
void* hmap_remove(struct hmap* self, char* key, void(*key_free)(void*));

#endif
