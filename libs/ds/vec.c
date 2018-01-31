#include "vec.h"

#include <string.h>
#include <stdlib.h>

struct vec* vec_create() {
	struct vec* v = (struct vec*)calloc(1, sizeof(struct vec));
	v->capacity = 8;
	v->items = (void**)calloc(v->capacity, sizeof(void*));
	return v;
}

int vec_push_back(struct vec* self, void* item) {
	if(self->length + 1 >= self->capacity) {
		void** new_items = (void**)realloc(self->items, sizeof(void*) * self->capacity * 2);
		if(!new_items)
			return 1;

		self->items = new_items;
		self->capacity *= 2;
	}

	self->items[self->length++] = item;
	return 0;
}

void* vec_pop_back(struct vec* self) {
	if(self->length == 0)
		return NULL;

	return self->items[--self->length];
}

void* vec_pop_at(struct vec* self, size_t index) {
	if(index >= self->length)
		return NULL;

	void* item = self->items[index];
	memmove(self->items + index, self->items + index + 1, sizeof(void*) * (self->length - index - 1));
	self->length -= 1;

	return item;
}
