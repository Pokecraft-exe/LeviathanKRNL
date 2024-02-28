#pragma once
#include "allocator.hpp"

class string {
private:
	bool allocated = false;
	char* _Ptr;
	size_t _size;
public:
	string(const string&);
	string(char*);
	size_t size();
	void destroy();
	char* c_str();
	bool isAllocated();
	void resize(int);
	char& operator[](int);
	string operator+(string);
	bool operator ==(string);
	bool operator ==(char*);
};