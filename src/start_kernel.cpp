//#include "H/KBscancodes.h"
#include "printf.h"
#include "font.hpp"
#include "IDT.h"
#include "allocator.hpp"
/*#include "sound.h"
#include "typedefs.h"
#include "kernel.h"
#include "mouse.h"
#include "errors.h"
//#include "Time.h"
#include "stddef.h"*/
#include "serial.h"
#include "memmap.hpp"
#define loop(x,n) for(int x = 0; x < n; ++x)

void delay(int clocks)
{
    asm("push %rax");
    for(uint64_t i = 0; i < clocks; i+=8){
        asm("xor %rax, %rax");
    }
    asm("pop %rax");
    return;
}

extern "C" void start_K(){
    //__BOOTSCREEN__();
    //MasterVolume = 100;
    //cls();
    //PlaySound(469,MasterVolume);
    bool reached_memmap = memmap_request();
    if (reached_memmap) DrawString("memmap", 0, 18, 0x00FF, 2);
    IRQ_set_all();
    init_serial();
    write_serial('a');
    InitIDT();
    add_IRQ(KEYBOARD, isr1_handler, IDT_IG);
	//add_IRQ(13, isr13, IDT_TG);
	//add_IRQ(14, isr14, IDT_TG);
    //add_IRQ(CMOS, cmos, IDT_IG);
    write_serial('b');
    //mouseinit();
    write_serial('c');
    DrawString("Hello World", 0, 8, 0x0000FF, 2);
    write_serial('e');
    
    //initRAMDISK();
    //restart();
    while(1) {   //mainloop
        asm("hlt;");
	}
    return;
}
