#include "H/KBscancodes.h"
#include "H/printf.h"
#include "H/IDT.h"
#include "H/sound.h"
#include "mouse.cpp"
#include "H/Memory.h"
#include "H/Heap.h"
#include "H/Colors.h"
#include "H/typedefs.h"

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
    // to do: GUI
    InitHeap(0x100000, 0x100000);
    malloc(0x4000);
    uint_64* Test = (uint_64*)aligned_Alloc(0x4000, 0x08);
    printf(HexToString((uint_64)Test));
    printf("\n");
    free(Test);

    uint_64* Test2 = (uint_64*)malloc(0x4000);
    printf(HexToString((uint_64)Test2));
    printf("\n");


    return;
}