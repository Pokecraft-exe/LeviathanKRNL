#pragma once
#define VGA_MEMORY (unsigned char*)0xb8000
#define VGA_WIDTH 80
#include "IO.h"
#include "typedefs.h"
#include "Colors.h"

extern uint_16 CursorPosition;
extern int ProtectedPos[2044];
void cls(uint_64 ClearColor = BACKGROUND_BLACK | FOREGROUND_WHITE);
void SetCursorPosition(unsigned short position);
uint_16 PositionFromCoords(uint_8 x, uint_8 y);
void printf(const char* str, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE, bool protectedstr = false);
void printchar(char chr, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE, bool protectedstr = false);

const char* HexToString(uint_8 value);
const char* HexToString(uint16 value);
const char* HexToString(uint_32 value);
const char* HexToString(uint_64 value);
const char* HexToString(char value);
const char* HexToString(short value);
const char* HexToString(int value);
const char* HexToString(long long value);

const char* IntToStr(uint_8 value);
const char* IntToStr(uint16 value);
const char* IntToStr(uint_32 value);
const char* IntToStr(uint_64 value);
const char* IntToStr(char value);
const char* IntToStr(short value);
const char* IntToStr(int value);
const char* IntToStr(long long value);

const char* FloatToString(float value, uint_8 decimalPlaces);