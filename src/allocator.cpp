#include "allocator.hpp"

Chunk_List alloced_chunks;
uint8_t HEAP[HEAP_CAPACITY] = { 0 };

void* memcpy(void* dest, const void* src, size_t len)
{
    char* d = (char*)dest;
    const char* s = (const char*)src;
    while (len--)
        *d++ = *s++;
    return dest;
}

void* memclear(void* dest, size_t len)
{
    char* d = (char*)dest;
    while (len--)
        *d++ = 0;
    return dest;
}

template int std::quickSort<Chunk>(Chunk*, bool (*)(Chunk, Chunk), int, int);

bool sort(Chunk a, Chunk b){
    return a.start < b.start;
}

bool init_heap() {
    uint64_t totalMemsize = memmap::get_memory_size(LIMINE_MEMMAP_ALL);
    uint64_t realHeapCapacity = totalMemsize - (uintptr_t)&HEAP;

    alloced_chunks.count = 2;
    alloced_chunks[0] = { (uintptr_t*)HEAP, 1 };

    alloced_chunks[1] = { (uintptr_t*)(HEAP + (realHeapCapacity - 1)), 1 };
    if (((uintptr_t)alloced_chunks[1].start + 1) - (uintptr_t)alloced_chunks[0].start == realHeapCapacity) return 1;
    return 0;
}

void free(void* ptr) {
    // search the current chunk remove it,
    // clear it and sort the chunks
    signed long long j = -1;
    for (size_t i = 0; i < alloced_chunks.count; i++) {
        if (alloced_chunks[i].start == (uintptr_t*)ptr) {
            j = i; 
            break;
        }
    }
    if (j == -1) return;
    size_t i = j; // convert to unsigned
    memclear(ptr, alloced_chunks[i].size);
    alloced_chunks[i].start = 0;
    alloced_chunks[i].size = 0;
    // sort the alloced chuncks
    std::quickSort<Chunk>(alloced_chunks.chunks, sort, 0, alloced_chunks.count);
    alloced_chunks.count--;
    // invert the last chunks
    Chunk t = alloced_chunks[alloced_chunks.count - 1];
    alloced_chunks[alloced_chunks.count - 1] = alloced_chunks[alloced_chunks.count];
    alloced_chunks[alloced_chunks.count] = t;
}

void* realloc(void* ptr, size_t size) {
    // allocate new size, copy content from last chunk
    // free last chunk
    if (size == 0) return nullptr;
    signed long long j = -1;
    for (size_t i = 0; i < alloced_chunks.count; i++) {
        if (alloced_chunks[i].start == (uintptr_t*)ptr) {
            j = i;
            break;
        }
    }
    if (j == -1) return nullptr;
    size_t i = j; // convert to unsigned
    uintptr_t* new_ptr = nullptr;
    Chunk* Last_chunk = &alloced_chunks[0];
    for (int i = 1; i < alloced_chunks.count; i++) {
        if (Last_chunk->start + Last_chunk->size != alloced_chunks[i].start) {
            // free chunk found
            size_t free_size = alloced_chunks[i].start - (Last_chunk->start + Last_chunk->size);
            if (free_size >= size) {
                new_ptr = (uintptr_t*)(Last_chunk->start) + Last_chunk->size + 1;
                alloced_chunks[alloced_chunks.count] = { new_ptr, size };
                alloced_chunks.count++;
                break;
            }
            Last_chunk = &alloced_chunks[i];
        }
    }
    memcpy(new_ptr, ptr, alloced_chunks[i].size);

    // free the last chunk
    memclear(ptr, alloced_chunks[i].size);
    alloced_chunks[i].start = 0;
    alloced_chunks[i].size = 0;
    // sort the alloced chuncks
    std::quickSort<Chunk>(alloced_chunks.chunks, sort, 0, alloced_chunks.count);
    alloced_chunks.count--;
    // invert the last chunks
    Chunk t = alloced_chunks[alloced_chunks.count - 1];
    alloced_chunks[alloced_chunks.count - 1] = alloced_chunks[alloced_chunks.count];
    alloced_chunks[alloced_chunks.count] = t;
    return new_ptr;
}

void* alloc(size_t size) {
    // remove or resize the 1st usable chunk in the 
    // freed chunks and return the pointer
    if (size == 0) return nullptr;

    uintptr_t* ptr = nullptr;
    Chunk* Last_chunk = &alloced_chunks[0];

    for (int i = 1; i < alloced_chunks.count; i++) {
        if (Last_chunk->start + Last_chunk->size != alloced_chunks[i].start) {
            // free chunk found
            size_t free_size = alloced_chunks[i].start - (Last_chunk->start + Last_chunk->size);
            if (free_size >= size) {
                ptr = (uintptr_t*)(Last_chunk->start) + Last_chunk->size + 1;
                alloced_chunks[alloced_chunks.count] = { ptr, size };
                alloced_chunks.count++;
                break;
            }
            Last_chunk = &alloced_chunks[i];
        }
    }
    std::quickSort<Chunk>(alloced_chunks.chunks, sort, 0, alloced_chunks.count);
    return ptr;
}
