#include "mouse.cpp"
#include "H/KBscancodes.h"
#include "H/printf.h"
#include "H/IDT.h"
//#include "H/sound.h"
#include "H/Memory.h"
#include "H/Heap.h"
#include "H/Colors.h"
#include "H/typedefs.h"
#include "H/vga.h"
#include "H/Font.h"
#include "H/serial.h"
#include "H/3D.h"
//#include "H/Time.h"
#define NULL ((void*)0)

char* gets(int s){
    char CHAR[s];
    int ptr = 0;
    while (1){
        if (read_serial() == 10){
            puts("\n\r");
            return CHAR;
        }else{
            CHAR[ptr] = KEY;
            write_serial(KEY);
            ptr++;
        }
    }
    return CHAR;
}

extern "C" void _start(){
    //__BOOTSCREEN__();
    InitHeap(0x100000, 0x100000);
    InitializeIDT();
    MainKeyboardHandler = Keyboardhandler;
    init_serial();
    puts(SERIALBLUE);puts((char*)"Initializing Serial [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing VGA [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing Heap [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing Memory Manangment [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing IDT's [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    mouseinit();
    puts(SERIALBLUE);puts((char*)"Initializing Mouse [");puts(SERIALRED);puts((char*)"ERROR");puts(SERIALBLUE);puts((char*)"]\n\r");
    MemoryMapEntry** usableMemoryMaps = GetUsableMemoryRegions();
    // TODO: font, mouse ,buttons and others
    puts(SERIALBLUE);puts((char*)"Initializing KeyBoard [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    //Making the windowMananger
    Window WindowMananger;
    puts(SERIALBLUE);puts((char*)"Initializing Windowing [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    //taskbar
    WindowMananger.NewWindow(0, 190, 360, 10, (char*)"");
    //double windowing test
    WindowMananger.NewWindow(10, 25, 50, 100, (char*)"TEST");
    KBmouse.x = 160;
    KBmouse.y = 100;
    ctmouse(160, 100);
    char* command = gets(100);
    puts(command);
    //draw_char('C', 100, 20);
    WindowMananger.Refresh();
    while(1) {   //mainloop
    //mouse_updater();

	}
    return;
}
