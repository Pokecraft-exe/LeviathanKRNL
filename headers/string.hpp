#pragma once
#include "lalloc.hpp"
typedef long unsigned int size_t;

class string{
private:
	char* str;
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
