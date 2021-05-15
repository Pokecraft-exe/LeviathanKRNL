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
    write_serial('c');
    //mouseinit();
    write_serial('d');
    // TODO: font, mouse ,buttons and others
    //taskbar
    WindowMananger.NewWindow(0, 190, 320, 10, (char*)"", 0);
    //double windowing test
    write_serial('e');
    WindowProperty* Win1 = WindowMananger.NewWindow(10, 25, 50, 100, (char*)"\n\r");
    KBmouse.x = 160;
    KBmouse.y = 100;
    ctmouse(160, 100);
    write_serial('f');
    //initRAMDISK();
    //restart();
    while(1) {   //mainloop
        Win1->left= Win1->left + 3;
        ctmouse(160, 100);
        if (Win1->left+Win1->right == 320) restart();
        /*mouse_updater(inb(0x60));
        MousePacket();
        PlaySound(1043,MasterVolume);for (int i = 0; i<200000;i++);{}
        PlaySound(1570,MasterVolume);for (int ii = 0; ii<200000;ii++);{}
        PlaySound(1969,MasterVolume);for (int iii = 0; iii<200000;iii++);{}
        PlaySound(1477,MasterVolume);for (int iiii = 0; iiii<200000;iiii++);{}*/
        
	}
    return;
}
