#pragma once
#ifndef KBSCANCODES
#define KBSCANCODES

#include "allocator.hpp"

extern bool ShiftPressed;
extern uint8_t LastScancode;

extern char * KEY;

const char ScanCodeLookupTable[] ={
    0, 0, '&', '2',
    34, 39, '(', '-',
    0, '_', '9', '0',
    ')', '=', 0, 0,
    'a', 'z', 'e', 'r',
    't', 'y', 'u', 'i',
    'o', 'p', '^', '$',
    0, 0, 'q', 's',
    'd', 'f', 'g', 'h',
    'j', 'k', 'l', 'm',
    '0', 0, 0, '*',
    'w', 'x', 'c', 'v',
    'b', 'n', ',', ';',
    ':', '!', 0, '*',
    0, ' '
  };
  
void StandardKeyboardHandler(uint8_t scancodes, uint8_t chr);
void KeyboardHandler0xE0(uint8_t scanCode);
void Keyboardhandler(uint8_t scancodes, uint8_t chr);
#endif
