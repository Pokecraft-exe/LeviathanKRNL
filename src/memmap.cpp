#include "limine.h"
#include "memmap.hpp"

static volatile struct limine_memmap_request limine_memmap_request = {
	LIMINE_MEMMAP_REQUEST,
    0
};

struct limine_memmap_response memmap::memmap;

uint64_t memmap::get_memory_size(uint8_t type) {
	uint64_t size = 0;
	if (type != 8) {
		for (uint16_t i = 0; i < memmap.entry_count; i++){
			if (memmap.entries[i]->type == type) {
				size += memmap.entries[i]->length;
			}
		}
		return size;
	} else {
		for (uint16_t i = 0; i < memmap.entry_count; i++){
			size += memmap.entries[i]->length;
		}
		return size;
	}
}

bool memmap::memmap_request() {
	if (limine_memmap_request.response == nullptr
     || limine_memmap_request.response->entry_count < 1) {
        return 0;
    }
 
    memmap.revision = limine_memmap_request.response->revision;
    memmap.entry_count = limine_memmap_request.response->entry_count;
    memmap.entries = limine_memmap_request.response->entries;
    return 1;
}

const char* memmap::get_memory_type(limine_memmap_entry* entry){
	switch (entry->type) {
		case LIMINE_MEMMAP_USABLE: 
			return "LIMINE_MEMMAP_USABLE";
		case LIMINE_MEMMAP_RESERVED: 
			return "LIMINE_MEMMAP_RESERVED";
		case LIMINE_MEMMAP_ACPI_RECLAIMABLE: 
			return "LIMINE_MEMMAP_ACPI_RECLAIMABLE";
		case LIMINE_MEMMAP_ACPI_NVS: 
			return "LIMINE_MEMMAP_ACPI_NVS";
		case LIMINE_MEMMAP_BAD_MEMORY: 
			return "LIMINE_MEMMAP_BAD_MEMORY";
		case LIMINE_MEMMAP_BOOTLOADER_RECLAIMABLE: 
			return "LIMINE_MEMMAP_BOOTLOADER_RECLAIMABLE";
		case LIMINE_MEMMAP_KERNEL_AND_MODULES: 
			return "LIMINE_MEMMAP_KERNEL_AND_MODULES";
		case LIMINE_MEMMAP_FRAMEBUFFER: 
			return "LIMINE_MEMMAP_FRAMEBUFFER";
	}
}
 
void *memset(void *s, int c, size_t n) {
    uint8_t *p = (uint8_t *)s;
 
    for (size_t i = 0; i < n; i++) {
        p[i] = (uint8_t)c;
    }
 
    return s;
}
 
void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;
 
    if (src > dest) {
        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) {
            pdest[i-1] = psrc[i-1];
        }
    }
 
    return dest;
}
 
int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *p1 = (const uint8_t *)s1;
    const uint8_t *p2 = (const uint8_t *)s2;
 
    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] < p2[i] ? -1 : 1;
        }
    }
 
    return 0;
}