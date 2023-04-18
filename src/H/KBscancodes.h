#pragma once
#ifndef KBSCANCODES
#define KBSCANCODES

#include "typedefs.h"
#include "printf.h"
#include "IDT.h"
#include "sound.h"

extern bool ShiftPressed;
extern uint_8 LastScancode;
extern string chrcode;

extern char KEY;

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
  
void StandardKeyboardHandler(uint8 scancodes, uint8 chr);
void KeyboardHandler0xE0(uint_8 scanCode);
void Keyboardhandler(uint8 scancodes, uint8 chr);
#endif
