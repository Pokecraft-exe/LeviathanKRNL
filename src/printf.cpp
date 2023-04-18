#include "H/printf.h"

uint_16 CursorPosition;
//for (i = 0; i = 2044; i++) ProtectedPos[i] = 0;

void cls(uint_64 ClearColor)
{
  uint_64 value =0;
  value += ClearColor << 8;
  value += ClearColor << 24;
  value += ClearColor << 40;
  value += ClearColor << 56;
  for (uint_64* i = (uint_64*)VGA_MEMORY; i < (uint_64*)(VGA_MEMORY + 4000); i++){
      *i = value;
  }
  SetCursorPosition(PositionFromCoords(0, 0));
}

void SetCursorPosition(unsigned short position){

  outb(0x3D4, 0x0F);
  outb(0x3D5, (uint_8)(position & 0xFF));
  outb(0x3D4, 0x0E);
  outb(0x3D5, (uint_8)((position >> 8) & 0xFF));

  CursorPosition = position;
}

uint_16 PositionFromCoords(uint_8 x, uint_8 y){
  return y * VGA_WIDTH + x;
}

void print(const char* str, uint_8 color){
  uint_16 index = CursorPosition;
  int i = 0;
  while(str[i] != 0)
  {
    if (str[i] == 10){
        index+= VGA_WIDTH;
        index -= index % VGA_WIDTH;
    } else {
        *(VGA_MEMORY + index * 2) = str[i];
        *(VGA_MEMORY + index * 2 + 1) = color;
        index++; 
    }
    i++;
    SetCursorPosition(index);
  }
  index+= VGA_WIDTH;
  index -= index % VGA_WIDTH;
  SetCursorPosition(index);
}

void printchar(char chr, uint_8 color, bool protectedstr){
    switch (chr) {
      case 10:
        SetCursorPosition(CursorPosition += VGA_WIDTH);
        SetCursorPosition(CursorPosition -= CursorPosition % VGA_WIDTH);
        break;
      case 13:
        SetCursorPosition(CursorPosition += VGA_WIDTH);
        SetCursorPosition(CursorPosition -= CursorPosition % VGA_WIDTH);
        break;
      default:
        *(VGA_MEMORY + CursorPosition * 2) = chr;
        *(VGA_MEMORY + CursorPosition * 2 + 1) = color;
        SetCursorPosition(CursorPosition + 1);
    }
    //drawchar(chr, 0, 0, 15);
}



char hexToStringOutput[128];
template<typename T>
char* HexToString(T value) {
    T* valPtr = &value;
    uint8_t* ptr;
    uint8_t temp;
    uint8_t size = (sizeof(T)) * 2 - 1;
    uint8_t i;
    for (i = 0; i < size; i++) {
        ptr = ((uint_8*)valPtr + i);
        temp = ((*ptr & 0xF0) >> 4);
        hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
        temp = ((*ptr & 0x0F));
        hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
    }
    hexToStringOutput[size + 1] = 0;
    return hexToStringOutput;
}

char* HexToString(void* value) {return HexToString<void*>(value);}
char* HexToString(uint8_t value) {return HexToString<uint_8>(value);}
char* HexToString(uint16_t value) {return HexToString<uint_16>(value);}
char* HexToString(uint32_t value) {return HexToString<uint_32>(value);}
char* HexToString(uint64_t value) {return HexToString<uint_64>(value);}
char* HexToString(char value) {return HexToString<char>(value);}
char* HexToString(short value) {return HexToString<short>(value);}
char* HexToString(int value) {return HexToString<int>(value);}
char* HexToString(long long value) {return HexToString<long long>(value);}

char integerToStringOutput[128];
template<typename T>
char* IntToStr(T value) {

	uint_8 isNegative = 0;

	if (value < 0) {
		isNegative = 1;
		value *= -1;
		integerToStringOutput[0] = '-';
	}

	uint_8 size = 0;
	uint_64 sizeTester = (uint_64)value;
	while (sizeTester / 10 > 0) {
		sizeTester /= 10;
		size++;
	}

	uint_8 index = 0;
	uint_64 newValue = (uint_64)value;
	while (newValue / 10 > 0) {
		uint_8 remainder = newValue % 10;
		newValue /= 10;
		integerToStringOutput[isNegative + size - index] = remainder + 48; 
		index++;
	}
	uint_8 remainder = newValue % 10;
	integerToStringOutput[isNegative + size - index] = remainder + 48;
	integerToStringOutput[isNegative + size + 1] = 0;
	return integerToStringOutput;
}

char* IntToStr(uint8_t value) {return IntToStr<uint_8>(value);}
char* IntToStr(uint16_t value) {return IntToStr<uint_16>(value);}
char* IntToStr(uint32_t value) {return IntToStr<uint_32>(value);}
char* IntToStr(uint64_t value) {return IntToStr<uint_64>(value);}
char* IntToStr(char value) {return IntToStr<char>(value);}
char* IntToStr(short value) {return IntToStr<short>(value);}
char* IntToStr(int value) {return IntToStr<int>(value);}
char* IntToStr(long long value) {return IntToStr<long long>(value);}

char floatToStringOutput[128];
char* FloatToString(float value, uint_8 decimalPlaces) {
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

	for (uint_8 i = 0; i < decimalPlaces; i++) {
		newValue *= 10;
		*floatPtr = (int)newValue + 48;
		newValue -= (int)newValue;
		floatPtr++;
	}

	*floatPtr = 0;

	return floatToStringOutput;
}
