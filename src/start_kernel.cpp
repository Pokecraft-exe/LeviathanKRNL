/*#include "H/KBscancodes.h"
#include "H/printf.h"
#include "H/IDT.h"
#include "H/sound.h"
#include "H/typedefs.h"

#include "H/mouse.h"
#include "H/errors.h"
//#include "H/Time.h"
#include "H/lalloc.h"
#include "H/stddef.h"
#include "H/Colors.h"*/
#include "H/serial.h"

void delay(int clocks)
{
    asm("push %rax");
    for(uint64 i = 0; i < clocks; i+=8){
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
    init_serial();
    write_serial('a');
    //InitIDT();
    //add_IRQ(KEYBOARD, isr1_handler, IDT_IG);
    write_serial('b');
    //mouseinit();
    write_serial('c');
    //print("Hello World");
    write_serial('e');
    
    //initRAMDISK();
    //restart();
    while(1) {   //mainloop
        asm("hlt;");
	}
    return;
}
