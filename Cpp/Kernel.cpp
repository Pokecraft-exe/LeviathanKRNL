#include "H/KBscancodes.h"
#include "H/printf.h"
#include "H/IDT.h"
#include "H/sound.h"
#include "mouse.cpp"
#include "H/Memory.h"

extern const char Text[];

extern "C" void _start(){
    MainKeyboardHandler = Keyboardhandler;
    InitIDT();
    mouse_install();
    SetCursorPosition(PositionFromCoords(0, 0));
    cls();
    beep(10000);
    printf("Kernel By pokecraft\n");
    printf("x64 Booting\n");
    printf(Text);
    printf("\nPress any Key to login.\n");
    MemoryMapEntry** usableMemoryMaps = GetUsableMemoryRegions();
    for (uint8 i = 0; i < UsableMemoryRegionCount; i++) {
        MemoryMapEntry* memMap = usableMemoryMaps[i];
        printMemMap(memMap, CursorPosition);

    }
    return;
}