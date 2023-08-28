#ifndef PRINTF
#define PRINTF

#include "font.hpp"
#include "kernel.h"

extern uint16_t CursorPosition;
void cls(uint32_t color = 0);
void SetCursorPosition(unsigned short position);
uint32_t PositionFromCoords(uint16_t x, uint16_t y);
void print(const char* str, uint32_t color = 0xffffff);
void printchar(char chr, uint32_t color = 0xffffff);
//void scanf(string address);

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
#endif
