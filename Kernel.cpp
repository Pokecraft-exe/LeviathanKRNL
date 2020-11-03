#include "KBscancodes.cpp"
#include "printf.cpp"
#include "IDT.cpp"
#include "sound.cpp"
#include "mouse.cpp"

extern const char Text[];

extern "C" void _start(){
    MainKeyboardHandler = Keyboardhandler;
    InitIDT();
    mouse_install();
    //isr12_handler();
    SetCursorPosition(PositionFromCoords(0, 0));
    cls();
    beep(10000);
    printf("x64 Booting\n");
    printf(Text);
    printf("\nPress any Key to login.\n");
    printf("Scan Codes Interrupts\n");
    return;
}
