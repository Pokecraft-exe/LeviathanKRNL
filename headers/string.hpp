#pragma once
#include "allocator.hpp"
typedef long unsigned int size_t;

class string{
private:
	char* _Ptr;
	size_t _size;
public:
	string();
	string(const char* a);
	size_t size();
	void destroy();
	string operator=(const char* a);
	const char* operator=(string a);
	string operator++(int);
	string operator--(int);
	string* operator*();
	const char operator[](int index);
	string operator+(string b);
};
