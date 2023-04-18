#pragma once
#define VGA_MEMORY (unsigned char*)0xb8000
#define VGA_WIDTH 80
#include "IO.h"
#include "typedefs.h"
#include "Colors.h"
#include "KBscancodes.h"
#include "Serial.h"
#include "lalloc.h"

extern uint_16 CursorPosition;
extern int ProtectedPos[2044];
void cls(uint_64 ClearColor = BACKGROUND_BLACK | FOREGROUND_WHITE);
void SetCursorPosition(unsigned short position);
uint_16 PositionFromCoords(uint_8 x, uint_8 y);
void SetColor(uint8_t fg = FOREGROUND_WHITE, uint8_t bg = BACKGROUND_BLACK);
void print(const char* str, bool no_return = 0);
void printchar(char chr, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE, bool protectedstr = false);
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

char* FloatToString(float value, uint_8 decimalPlaces);
