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
int hmap_put(struct hmap* self, char* key, void* value);
void* hmap_get(struct hmap* self, char* key);
void* hmap_remove(struct hmap* self, char* key);

#endif
