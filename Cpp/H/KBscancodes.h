#include "typedefs.h"
#include "printf.h"

extern bool ShiftPressed;
extern uint_8 LastScancode;
extern string chrcode;

void StandardKeyboardHandler(uint8 scancodes, uint8 chr);
void KeyboardHandler0xE0(uint_8 scanCode);
void Keyboardhandler(uint8 scancodes, uint8 chr);