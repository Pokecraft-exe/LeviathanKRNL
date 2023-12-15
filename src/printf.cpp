#include "printf.h"
#include "serial.h"

int VGA_WIDTH;
uint16_t Console_size = (framebuffer->width*framebuffer->height)/16;
//for (i = 0; i = 2044; i++) ProtectedPos[i] = 0;

void cls(uint32_t color)
{
	uint32_t max = framebuffer->width*framebuffer->height;
	uint32_t *fb = (uint32_t*)framebuffer->address;
	for (uint32_t i = 0; i <= max; i++) {
		fb[i] = color;
	}
}

void SetCursorPosition(uint16_t position){
  CursorPosition = position;
}

uint16_t PositionFromCoords(uint8_t x, uint8_t y){
  return y * VGA_WIDTH + x;
}

struct point{
	int x;
	int y;
};

void printNoReturn(const char* str, uint32_t color) {
	while (*str) {
    if (*str == '\n'){
        CursorPosition += VGA_WIDTH;
        CursorPosition -= CursorPosition % VGA_WIDTH;
    } else {
	    int x, y;
        y = CursorPosition / VGA_WIDTH;
        x = CursorPosition % VGA_WIDTH;
        DrawCharBackground(*str++, x*16, y*16, color, 0, 2);
        CursorPosition++;
    }
  }
}

void print(const char* str, uint32_t color){
  while (*str) {
    if (*str == '\n'){
        CursorPosition += VGA_WIDTH;
        CursorPosition -= CursorPosition % VGA_WIDTH;
    } else {
	    int x, y;
        y = CursorPosition / VGA_WIDTH;
        x = CursorPosition % VGA_WIDTH;
        DrawCharBackground(*str++, x*16, y*16, color, 0, 2);
        CursorPosition++;
    }
  }
  CursorPosition += VGA_WIDTH;
  CursorPosition -= CursorPosition % VGA_WIDTH;
}

extern "C" void fprint(const char* str) {
   print(str, 0xffffff);
}

void printchr(const char chr, uint32_t color){
  int x, y;
  if (chr == '\n'){
        CursorPosition += VGA_WIDTH;
        CursorPosition -= CursorPosition % VGA_WIDTH;
  }
  else {
	y = CursorPosition / VGA_WIDTH;
  	x = CursorPosition % VGA_WIDTH;
  	DrawCharBackground(chr, x*16, y*16, color, 0, 2);
  	CursorPosition++;
  }
}

char string[67];
template <typename T>
char* binToStr(T value) {
	string = "0b\0";
	
	for (int i = 0; i < sizeof(T) * 8; i++) {
		string[i] = (value & (0x80>>(i%8))) + 48;
	}
	return string;
}

char* binToStr(uint8_t value) {return binToStr(value);}
char* binToStr(uint16_t value) {return binToStr(value);}
char* binToStr(uint32_t value) {return binToStr(value);}
char* binToStr(uint64_t value) {return binToStr(value);}

char hexToStringOutput[128];
template<typename T>
char* HexToString(T value) {
    T* valPtr = &value;
    uint8_t* ptr;
    uint8_t temp;
    uint8_t size = (sizeof(T)) * 2 - 1;
    uint8_t i;
    for (i = 0; i < size; i++) {
        ptr = ((uint8_t*)valPtr + i);
        temp = ((*ptr & 0xF0) >> 4);
        hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
        temp = ((*ptr & 0x0F));
        hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
    }
    hexToStringOutput[size + 1] = 0;
    return hexToStringOutput;
}

char* HexToString(void* value) {return HexToString<void*>(value);}
char* HexToString(uintptr_t* value) {return HexToString<void*>(value);}
char* HexToString(uint8_t value) {return HexToString<uint8_t>(value);}
char* HexToString(uint16_t value) {return HexToString<uint16_t>(value);}
char* HexToString(uint32_t value) {return HexToString<uint32_t>(value);}
char* HexToString(uint64_t value) {return HexToString<uint64_t>(value);}
char* HexToString(char value) {return HexToString<char>(value);}
char* HexToString(short value) {return HexToString<short>(value);}
char* HexToString(int value) {return HexToString<int>(value);}
char* HexToString(long long value) {return HexToString<long long>(value);}

char integerToStringOutput[128];
template<typename T>
char* IntToStr(T value) {

	uint8_t isNegative = 0;

	if (value < 0) {
		isNegative = 1;
		value *= -1;
		integerToStringOutput[0] = '-';
	}

	uint8_t size = 0;
	uint64_t sizeTester = (uint64_t)value;
	while (sizeTester / 10 > 0) {
		sizeTester /= 10;
		size++;
	}

	uint8_t index = 0;
	uint64_t newValue = (uint64_t)value;
	while (newValue / 10 > 0) {
		uint8_t remainder = newValue % 10;
		newValue /= 10;
		integerToStringOutput[isNegative + size - index] = remainder + 48; 
		index++;
	}
	uint8_t remainder = newValue % 10;
	integerToStringOutput[isNegative + size - index] = remainder + 48;
	integerToStringOutput[isNegative + size + 1] = 0;
	return integerToStringOutput;
}

char* IntToStr(uint8_t value) {return IntToStr<uint8_t>(value);}
char* IntToStr(uint16_t value) {return IntToStr<uint16_t>(value);}
char* IntToStr(uint32_t value) {return IntToStr<uint32_t>(value);}
char* IntToStr(uint64_t value) {return IntToStr<uint64_t>(value);}
char* IntToStr(char value) {return IntToStr<char>(value);}
char* IntToStr(short value) {return IntToStr<short>(value);}
char* IntToStr(int value) {return IntToStr<int>(value);}
char* IntToStr(long long value) {return IntToStr<long long>(value);}

char floatToStringOutput[128];
char* FloatToString(float value, uint8_t decimalPlaces) {
	char* intPtr = (char*)IntToStr((int)value);
	char* floatPtr = floatToStringOutput;

	if (value < 0) {
		value *= -1;
	}

	while (*intPtr != 0) {
		*floatPtr = *intPtr;
		intPtr++;
		floatPtr++;
	}
	*floatPtr = '.';
	floatPtr++;

	float newValue = value - (int)value;

	for (uint8_t i = 0; i < decimalPlaces; i++) {
		newValue *= 10;
		*floatPtr = (int)newValue + 48;
		newValue -= (int)newValue;
		floatPtr++;
	}

	*floatPtr = 0;

	return floatToStringOutput;
}

