#include "Heap.h"
#include "Memory.h"
#include "stddef.h"
int strcmp(const char * a, const char * b);
const char* strncat(const char* string1, const char* string2, uint32_t n);
uint32_t strlen(const char *str);
uint32_t __strlen(const char *str, uint32_t mexlen);
char * strdup(const char *str);
char * strcpy(char * dest, const char * src);
char * strtok_r(char * str, const char * delim, char ** saveptr);
size_t lfind(const char * str, const char accept);
size_t rfind(const char * str, const char accept);
char * strstr(const char * haystack, const char * needle);
size_t strspn(const char * str, const char * accept);
char * strpbrk(const char * str, const char * accept);