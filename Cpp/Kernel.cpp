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
    
    InitHeap(0x100000, 0x100000);
    void* TestMemoryAdress = malloc(0x10);
    void* TestMemoryAdress2 = malloc(0x10);
    void* TestMemoryAdress3 = malloc(0x10);
    printf(HexToString((uint_64) TestMemoryAdress));
    printf("\n");
    printf(HexToString((uint_64) TestMemoryAdress2));
    printf("\n");
    printf(HexToString((uint_64) TestMemoryAdress3));

    free(TestMemoryAdress);
    free(TestMemoryAdress2);
    free(TestMemoryAdress3);

    void* Test4 = malloc(0x60);
    printf("\n");
    printf(HexToString((uint_64) Test4));

    return;
}