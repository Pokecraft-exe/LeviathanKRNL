#pragma once
#include <stddef.h>
#include <stdint.h>
//#define NULL 0
#define HEAP_CAPACITY 0x1000000
#define CHUNK_LIST_CAP 2048

typedef struct {
	uintptr_t* start;
	size_t size;
} Chunk;

class Chunk_List {
public:
	size_t count;
	Chunk chunks[CHUNK_LIST_CAP];

	size_t Search(size_t low, size_t high, uintptr_t* x) {
		for (size_t i = 0; i < count; i++) {
			if (chunks[i].start == x) {
				return i;
			}
		}
		/*size_t mid = 0;
		while (low != high) {
			mid = (low + high) / 2;
			if (x == chunks[mid].start)	return mid;
			else if (x > chunks[mid].start) low = mid + 1;
			else high = mid - 1;
		}*/
		return -1;
	}
	Chunk& operator[](int i) {
		return this->chunks[i];
	}
};

void free(void* ptr);
void* realloc(void* ptr, size_t size);
void* alloc(size_t size);
