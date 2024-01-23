#include "string"

int strcmp (const char *p1, const char *p2)
{
  const unsigned char *s1 = (const unsigned char *) p1;
  const unsigned char *s2 = (const unsigned char *) p2;
  unsigned char c1, c2;
  do
    {
      c1 = (unsigned char) *s1++;
      c2 = (unsigned char) *s2++;
      if (c1 == '\0')
	return c1 - c2;
    }
  while (c1 == c2);
  return c1 - c2;
}
int strlen(const char* str) {
	int i = 0;
	while(str[i++] != 0);
	return i;
}

string::string(const string& a){
	if (allocated) free(_Ptr);
	_size = this->size();
	allocated = this->isAllocated();
	_Ptr = this->c_str();
}
string::string(char* a) {
	if (allocated) free(_Ptr);
	_Ptr = a;
	_size = strlen(a);
	allocated = false;
}
void string::resize(int nsize) {
	if (allocated) free(_Ptr);
	_Ptr = (char*)alloc(nsize);
	_size = nsize;
	allocated = true;
}
void string::destroy() { 
	if (allocated) free(_Ptr);
	allocated = false;
 }
char& 	string::operator[](int index) 	{ return _Ptr[index]; }
string 	string::operator+(string b) 	{ return ""; }
bool 	string::operator ==(string b) 	{ return strcmp(_Ptr, b.c_str()) == 0; }
bool 	string::operator ==(char* b) 	{ return strcmp(_Ptr, b) == 0; }
char* 	string::c_str() 				{ return _Ptr; }
bool 	string::isAllocated() 			{ return allocated; }
size_t 	string::size() 					{ return _size; }