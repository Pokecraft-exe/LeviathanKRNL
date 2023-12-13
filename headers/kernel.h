#ifndef kernel
#define kernel

#include <stdint.h>
#include <stddef.h>
#include "limine.h"
 
extern struct limine_framebuffer *framebuffer;
uint32_t RGB(uint8_t R, uint8_t G, uint8_t B);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
#endif
