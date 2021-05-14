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
//#include "H/2D.h"
#include "H/mouse.h"
//#include "H/Time.h"
#include "H/stddef.h"
#include "H/ramdisk.h"
#include "H/cstring.h"
extern "C" uint16_t Total_paged;
void delay(int clocks)
{
    asm("push %rax");
    for(uint64 i = 0; i < clocks; i+=8){
        asm("xor %rax, %rax");
    }
    asm("pop %rax");
    return;
}

extern "C" void _start(){
    //__BOOTSCREEN__();
    MasterVolume = 100;
    
    //PlaySound(469,MasterVolume);
    MemoryMapEntry** usableMemoryMaps = GetUsableMemoryRegions();
    InitHeap(0x100000, 0x100000);
    write_serial('a');
    //IDT MainInterrupt;
    //MainInterrupt.InitIDT();
    MainKeyboardHandler = Keyboardhandler;
    write_serial('b');
    init_serial();
    char* a=SERIALBLUE;
    char* b="Initializing Serial [OK]\n\rInitializing VGA [OK]\n\r";
    for(int i;a[i]!=0;i++){
        write_serial(a[i]);
    }
    free(&a);
    for(int i;b[i]!=0;i++){
        write_serial(b[i]);
    }
    write_serial('c');
    //puts("Paged:");puts(SERIALGREEN);puts(IntToStr(Total_paged));puts("kb\n\r");
    puts(SERIALBLUE);puts("Initializing Heap [");puts(SERIALGREEN);puts("Ok");puts(SERIALBLUE);puts("]\n\r");
    puts(SERIALBLUE);puts("Initializing Memory Manangment [");puts(SERIALGREEN);puts("Ok");puts(SERIALBLUE);puts("]\n\r");
    puts(SERIALBLUE);puts("Initializing IDT's [");puts(SERIALGREEN);puts("Ok");puts(SERIALBLUE);puts("]\n\r");
    write_serial('d');
    //mouseinit();
    puts(SERIALBLUE);puts("Initializing Mouse [");puts(SERIALRED);puts("ERROR");puts(SERIALBLUE);puts("]\n\r");
    // TODO: font, mouse ,buttons and others
    puts(SERIALBLUE);puts("Initializing KeyBoard [");puts(SERIALGREEN);puts("Ok");puts(SERIALBLUE);puts("]\n\r");
    //Making the windowMananger
    puts(SERIALBLUE);puts("Initializing Windowing [");puts(SERIALGREEN);puts("Ok");puts(SERIALBLUE);puts("]\n\r");
    //taskbar
    write_serial('e');
    WindowProperty* Win1 = WindowMananger.NewWindow(0, 190, 320, 10, (char*)"", 0);
    //double windowing test
    write_serial('f');
    WindowMananger.NewWindow(10, 25, 50, 100, (char*)"\n\r");
    KBmouse.x = 160;
    KBmouse.y = 100;
    //ctmouse(160, 100);
    WindowMananger.Refresh();
    write_serial('g');
    puts("Refresh\r\n");
    write_serial('h');//initRAMDISK();
    puts(SERIALBLUE);puts("Initializing RAMDISK [");puts(SERIALGREEN);puts("Ok");puts(SERIALBLUE);puts("]\n\r");
    
    /*physics Physics;
    Physics.setWater(200,50);
	Physics.setWater(201,51);
    Physics.iterate(2);*/
    //restart();
    while(1) {   //mainloop
        Win1->top++;
        /*mouse_updater(inb(0x60));
        MousePacket();
        PlaySound(1043,MasterVolume);for (int i = 0; i<200000;i++);{}
        PlaySound(1570,MasterVolume);for (int ii = 0; ii<200000;ii++);{}
        PlaySound(1969,MasterVolume);for (int iii = 0; iii<200000;iii++);{}
        PlaySound(1477,MasterVolume);for (int iiii = 0; iiii<200000;iiii++);{}*/
        
	}
    return;
}
