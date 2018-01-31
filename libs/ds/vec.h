#ifndef __VEC_H__
#define __VEC_H__

#include <stdlib.h>

struct vec {
	void** items;
	size_t length;
	size_t capacity;
};

struct vec* vec_create();
void vec_destroy(struct vec* self, void(*item_free)(void*));
int vec_push_back(struct vec* self, void* item);
void* vec_pop_back(struct vec* self);
void* vec_pop_at(struct vec* self, size_t index);

#endif
