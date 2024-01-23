#pragma once
#ifndef KBSCANCODES
#define KBSCANCODES

#include "allocator.hpp"

extern bool ShiftPressed;
extern uint8_t LastScancode;

extern char KEY;

extern const char ScanCodeLookupTable[];
  
void StandardKeyboardHandler(uint8_t scancodes, uint8_t chr);
void KeyboardHandler0xE0(uint8_t scanCode);
void Keyboardhandler(uint8_t scancodes);
#endif
