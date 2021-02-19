#include "H/KBscancodes.h"
#include "H/printf.h"
#include "H/IDT.h"
#include "H/sound.h"
#include "H/Memory.h"
#include "H/Heap.h"
#include "H/Colors.h"
#include "H/typedefs.h"
#include "H/vga.h"
#include "H/Font.h"
#include "H/serial.h"
#include "H/3D.h"
#include "H/mouse.h"
//#include "H/Time.h"
#include "H/stddef.h"

void delay(int clocks)
{
    asm("push %rax");
    for(uint64 i = 0; i < clocks; i+=8){
        asm("xor %rax, %rax");
    }
    asm("pop %rax");
    return;
}

/*void lvga(char mode){
    switch (mode){
        case 1:
            asm("mov %ah, $0h");
            asm("mov %al, $13h");
            asm("int $0x10");
            break;
        case 2:
            asm("mov %ah, $0h");
            asm("mov %al, $13h");
            asm("int $0x10");
            breakudu;
        default:
            debug("uncognized mode",mode);
   }
}*/

extern "C" void _start(){
    //__BOOTSCREEN__();
    MasterVolume = 100;
    
    //PlaySound(469,MasterVolume);
    InitHeap(0x100000, 0x100000);
    InitializeIDT();
    MainKeyboardHandler = Keyboardhandler;
    init_serial();
    puts(SERIALBLUE);puts((char*)"Initializing Serial [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing VGA [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing PAGING [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing Heap [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing Memory Manangment [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    puts(SERIALBLUE);puts((char*)"Initializing IDT's [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    mouseinit();
    puts(SERIALBLUE);puts((char*)"Initializing Mouse [");puts(SERIALRED);puts((char*)"ERROR");puts(SERIALBLUE);puts((char*)"]\n\r");
    MemoryMapEntry** usableMemoryMaps = GetUsableMemoryRegions();
    // TODO: font, mouse ,buttons and others
    puts(SERIALBLUE);puts((char*)"Initializing KeyBoard [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    //Making the windowMananger
    puts(SERIALBLUE);puts((char*)"Initializing Windowing [");puts(SERIALGREEN);puts((char*)"Ok");puts(SERIALBLUE);puts((char*)"]\n\r");
    //taskbar
    WindowMananger.NewWindow(0, 190, 320, 10, (char*)"", 0);
    char i[35]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
    WindowMananger.Label(i,0,0);
    Screen1.swap();
    //double windowing test
    WindowMananger.NewWindow(10, 25, 50, 100, (char*)"\n\r");
    KBmouse.x = 160;
    KBmouse.y = 100;
    //ctmouse(160, 100);
    puts("Refresh");
    //WindowMananger.Refresh();
    while(1) {   //mainloop
        mouse_updater(inb(0x60));
        MousePacket();
        /*PlaySound(1043,MasterVolume);for (int i = 0; i<200000;i++);{}
        PlaySound(1570,MasterVolume);for (int ii = 0; ii<200000;ii++);{}
        PlaySound(1969,MasterVolume);for (int iii = 0; iii<200000;iii++);{}
        PlaySound(1477,MasterVolume);for (int iiii = 0; iiii<200000;iiii++);{}*/
        
	}
    return;
}
