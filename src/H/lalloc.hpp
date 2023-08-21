#pragma once
#ifndef LALLOC
#define LALLOC
#include "typedefs.h"
#define NULL 0
#define HEAP_CAPACITY 0x100000
#define CHUNK_LIST_CAP 1024
typedef long unsigned int size_t;

typedef struct {
	uintptr_t* start;
	size_t size;
} Chunk;

class Chunk_List{
public:
	size_t count;
	Chunk chunks[CHUNK_LIST_CAP];

	size_t Search(size_t low, size_t high, uintptr_t *x) {
		size_t mid = 0;
		while (low != high) {
			mid = (low + high) / 2;
			if (x == chunks[mid].start)	return mid;
			else if (x > chunks[mid].start) low = mid + 1;
			else high = mid - 1;
		}
		return NULL;
	}
};

typedef struct {
	uintptr_t* list_addr;
	size_t free_chuck_count;
	Chunk next_free_chunk;
	uintptr_t* heap_addr;
	size_t heap_size;
	size_t used;
} heap_details;

void free(void* ptr);
void* realloc(void* ptr, size_t size);
void* alloc(size_t size);
size_t get_used();
heap_details get_details();
#endif
