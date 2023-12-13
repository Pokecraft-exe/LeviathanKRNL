#include "limine.h"
#define LIMINE_MEMMAP_ALL 8
typedef long unsigned int size_t;

namespace memmap {
    extern struct limine_memmap_response memmap;
    bool memmap_request();
    uint64_t get_memory_size(uint8_t type);
    const char* get_memory_type(limine_memmap_entry* entry);
}

void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);