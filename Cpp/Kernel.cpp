#include "H/KBscancodes.h"
#include "H/printf.h"
#include "H/IDT.h"
#include "H/sound.h"
#include "mouse.cpp"
#include "H/Memory.h"
#include "H/Heap.h"
#include "H/Colors.h"
#include "H/typedefs.h"
#include "H/vga.h"
//#include "Shell.cpp"

extern const char Text[];

extern "C" void _start(){
    char * vga = (char*)0xA0000;
    for (int i = 0; i < 307200; i++){
        vga[i] = 0x2;
    }
    MainKeyboardHandler = Keyboardhandler;
    InitIDT();
    mouse_install();
    cls();
    beep(10000);
    printf("Kernel By pokecraft\n");
    printf("x64 Booting\n");
    printf(Text);
    printf("\nPress any Key to login.\n");

    MemoryMapEntry** usableMemoryMaps = GetUsableMemoryRegions();
    // TODO:scanf, shell
    InitHeap(0x100000, 0x100000);
    //for (int32 y = 0; y < 200; y++){
        //for (int32 x = 0; x < 320; x++){
            //putPixel(x, y, 0x00, 0xA8, 0x00);
        //}
    //}
    window(45, 10, 100, 51);

    //Shell();
    while(1)
    return;
}