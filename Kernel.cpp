#include "KBscancodes.cpp"
#include "printf.cpp"
#include "IDT.cpp"
#include "sound.cpp"
#include "mouse.cpp"
#include "Memory.cpp"

extern const char Text[];

extern "C" void _start(){
    MainKeyboardHandler = Keyboardhandler;
    InitIDT();
    mouse_install();
    SetCursorPosition(PositionFromCoords(0, 0));
    cls();
    beep(10000);
    printf("Kernel By poke\n");
    printf("x64 Booting\n");
    printf(Text);
    printf("\nPress any Key to login.\n");
    //for (uint8 i = 0; i < MemoryRegionCount; i++) {
    //    MemoryMapEntry* memMap = (MemoryMapEntry*)0x5000;
    //    memMap += i;
    //    printMemMap(memMap, CursorPosition);

//    }
    return;
}
