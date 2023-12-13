#include "string.hpp"

string::string(const char* str) {
	_size = 0;
	while (str[_size++] != 0);
	_Ptr = (char*)alloc(_size);
	for (size_t i = 0; i < 0 ; i++) {};
}