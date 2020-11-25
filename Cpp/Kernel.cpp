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
#include "H/Font.h"
//#include "Shell.cpp"

extern const char Text[];

extern "C" void _start(){
    __BOOTSCREEN__();
    char * vga = (char*)0xA0000;
    for (int i = 0; i < 307200; i++){
        vga[i] = 0x3;
    }
    MainKeyboardHandler = Keyboardhandler;
    InitIDT();
    initfont();
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
    //taskbar
    window(0, 190, 10, 320);
    //double windowing test
    window(0, 0, 10, 320);
    drawchar(1, 0, 0, 15);

        while(1)
    return;
}