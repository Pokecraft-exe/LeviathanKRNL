#include "H/IO.h"
#include "H/IDT.h"
#include "H/typedefs.h"
#include "H/vga.h"

//extern int get_mouse_pos_x;
//extern int get_mouse_pos_x;

void mouse_wait(unsigned char type)
{
  unsigned int _time_out=100000;
  if(type==0)
  {
    while(_time_out--) //Data
    {
      if((inb(0x64) & 1)==1)
      {
        return;
      }
    }
    return;
  }
  else
  {
    while(_time_out--) //Signal
    {
      if((inb(0x64) & 2)==0)
      {
        return;
      }
    }
    return;
  }
}
void mouse_write(unsigned char a_write)
{
 //Wait to be able to send a command
 mouse_wait(1);
 //Tell the mouse we are sending a command
 outb(0x64, 0xD4);
 //Wait for the final part
 mouse_wait(1);
 //Finally write
 outb(0x60, a_write);
}

unsigned char mouse_read()
{
 //Get response from mouse
 mouse_wait(0);
 return inb(0x60);
}

 void mouseinit()
{
    mouse_wait(1);
    outb(0x64,0xA8);
    mouse_wait(1);
    outb(0x64,0x20);
    unsigned char status_byte;
    mouse_wait(0);
    status_byte = (inb(0x60) | 2);
    mouse_wait(1);
    outb(0x64, 0x60);
    mouse_wait(1);
    outb(0x60, status_byte);
    mouse_write(0xF6);
    mouse_read();
    mouse_write(0xF4);
    mouse_read();
    //interruptHandlerRegister(12,&mouse_handler);
}
/*	uint8 mouse_cycle=0;
	int8 mouse_byte[3];
  int I;
void mouse_updater()
{
  	switch(mouse_cycle)
  {
    case 0:
      I = 0;
      mouse_byte[0]=inb(0x60);
      mouse_cycle++;
      break;
    case 1:
      if (KBmouse.x+inb(0x60) >= 320 || KBmouse.x+inb(0x60) <= 0){
       KBmouse.x=KBmouse.x;
      }else{
      KBmouse.velox=inb(0x60)/4;}
      mouse_cycle++;
      break;
    case 2:
      if (KBmouse.y-inb(0x60) >= 200 || KBmouse.y-inb(0x60) <= 0){
        KBmouse.y=KBmouse.y;
      }else{
      KBmouse.veloy=inb(0x60);
      //while (I != 1000){I++;}
      }
      KBmouse.x+=0;//KBmouse.velox;
      KBmouse.y-=0;//KBmouse.veloy;
      ctmouse(KBmouse.x, KBmouse.y);
      mouse_cycle=0;
      break;
  }
}

*/