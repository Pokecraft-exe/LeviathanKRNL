#pragma once
#define VGA_MEMORY (unsigned char*)0xb8000
#define VGA_WIDTH 80
#include "IO.h"
#include "typedefs.h"
#include "Colors.h"
#include "KBscancodes.h"

extern uint_16 CursorPosition;
extern int ProtectedPos[2044];
void cls(uint_64 ClearColor = BACKGROUND_BLACK | FOREGROUND_WHITE);
void SetCursorPosition(unsigned short position);
uint_16 PositionFromCoords(uint_8 x, uint_8 y);
void printf(char* str, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE, bool protectedstr = false);
void printchar(char chr, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE, bool protectedstr = false);
//void scanf(string address);

char* HexToString(uint_8 value);
char* HexToString(uint16 value);
char* HexToString(uint_32 value);
char* HexToString(uint_64 value);
char* HexToString(char value);
char* HexToString(short value);
char* HexToString(int value);
char* HexToString(long long value);

char* IntToStr(uint_8 value);
char* IntToStr(uint16 value);
char* IntToStr(uint_32 value);
char* IntToStr(uint_64 value);
char* IntToStr(char value);
char* IntToStr(short value);
char* IntToStr(int value);
char* IntToStr(long long value);

char* FloatToString(float value, uint_8 decimalPlaces);