#ifndef PRINTF
#define PRINTF

#include "font.hpp"
#include "allocator.hpp"
#include "kernel.h"

extern int VGA_WIDTH;
extern uint16_t CursorPosition;
extern bool CursorShown;
void cls(uint32_t color = 0);
void SetCursorPosition(unsigned short position);
uint16_t PositionFromCoords(uint8_t x, uint8_t y);
void print(const char* str, uint32_t color = 0xffffff);
void printNoReturn(const char* str, uint32_t color = 0xffffff);
void printchr(const char chr, uint32_t color = 0xffffff);
void deletechr();

char* binToStr(uint8_t value);
char* binToStr(uint16_t value);
char* binToStr(uint32_t value);
char* binToStr(uint64_t value);

char* HexToString(void* value);
char* HexToString(uintptr_t* value);
char* HexToString(uint8_t value);
char* HexToString(uint16_t value);
char* HexToString(uint32_t value);
char* HexToString(uint64_t value);
char* HexToString(char value);
char* HexToString(short value);
char* HexToString(int value);
char* HexToString(long long value);

char* IntToStr(uint8_t value);
char* IntToStr(uint16_t value);
char* IntToStr(uint32_t value);
char* IntToStr(uint64_t value);
char* IntToStr(char value);
char* IntToStr(short value);
char* IntToStr(int value);
char* IntToStr(long long value);

char* FloatToString(float value, uint8_t decimalPlaces);

/*class stdcout {
	private:
		int width;
		uint16_t* position;
	public:
		stdcout(int _width, uint16_t* _position) {
			width = _width;
			position = position;
		}
		opaerator<<(const char* str) {
			print(str, 0xffffff, *position, width);
		}
}*/

#endif
