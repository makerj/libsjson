#include "hmap.h"

#include  <stdint.h>
#include  <string.h>

struct hmap* hmap_create() {
	struct hmap* h = (struct hmap*)calloc(1, sizeof(struct hmap));
	h->capacity = 8;
	h->buckets = (struct vec**)calloc(h->capacity, sizeof(struct vec*));
	for(size_t i = 0; i < h->capacity; ++i) {
		h->buckets[i] = vec_create();
	}
	return h;
}

void hmap_destroy(struct hmap* self, void(*key_free)(void*), void(*value_free)(void*)) {
	for(size_t i = 0; i < self->capacity; ++i) {
		struct vec* bucket = self->buckets[i];
		if(!bucket)
			continue;

		for(size_t j = 0; j < bucket->length; ++j) {
			struct hmap_entry* e = (struct hmap_entry*)bucket->items[j];
			if(key_free)
				key_free(e->key);
			if(value_free)
				value_free(e->value);
			free(e);
		}
		vec_destroy(bucket, NULL);
	}
	free(self->buckets);
	free(self);
}

int hmap_put(struct hmap* self, char* key, void* value) {
	size_t bucket_id = (uintptr_t)key % self->capacity;

	struct hmap_entry* entry = (struct hmap_entry*)calloc(1, sizeof(struct hmap_entry));
	entry->key = key;
	entry->value = value;

	int error =  vec_push_back(self->buckets[bucket_id], entry);
	if(error) {
		free(entry);
		return 1;
	}

	self->length += 1;
	return 0;
}

void* hmap_get(struct hmap* self, char* key) {
	int bucket_id = (uintptr_t)key % self->capacity;

	for(size_t i = 0; i < self->buckets[bucket_id]->length; ++i) {
		struct hmap_entry* e = (struct hmap_entry*)self->buckets[bucket_id]->items[i];
		if(strcmp(e->key, key) == 0) {
			return e->value;
		}
	}

	return NULL;
}

void* hmap_remove(struct hmap* self, char* key, void(*key_free)(void*)) {
	int bucket_id = (uintptr_t)key % self->capacity;

	for(size_t i = 0; i < self->buckets[bucket_id]->length; ++i) {
		struct hmap_entry* e = (struct hmap_entry*)self->buckets[bucket_id]->items[i];
		if(strcmp(e->key, key) == 0) {
			void* key = e->key;
			void* value = e->value;
			free(e);
			vec_pop_at(self->buckets[bucket_id], i);

			self->length -= 1;

			if(key_free)
				key_free(key);

			return value;
		}
	}

	return NULL;
}

