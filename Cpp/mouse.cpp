#include "H/mouse.h"

mouse KBmouse;
bool GetLeftClick(){
	return KBmouse.mouseLeftClick;
}
bool GetRightClick(){
	return KBmouse.mouseRightClick;
}
bool GetClick(){
	return KBmouse.mouseClick;
}
bool GetMouseUp(){
	return KBmouse.mouseUp;
}
bool GetMouseDown(){
	return KBmouse.mouseDown;
}
bool GetMouseLeft(){
	return KBmouse.mouseLeft;
}
bool GetMouseRight(){
	return KBmouse.mouseRight;
}
int GetMouseX(){
	return KBmouse.x;
}
int GetMouseY(){
	return KBmouse.y;
}
int GetMouseVelocityX(){
	return KBmouse.velox;
}
int GetMouseVelocityY(){
	return KBmouse.veloy;
}

void mouse_wait()
{
  unsigned int _time_out=100000;
  while(_time_out--) //Data
  {
    if((inb(0x64) & 0b10)==0)
    {
      return;
    }
  }
    return;
}

void mousewait()
{
  unsigned int _time_out=100000;
  while(_time_out--) //Data
  {
    if(inb(0x64) & 0b1)
    {
      return;
    }
  }
    return;
}

void mouse_write(unsigned char a_write)
{
 //Wait to be able to send a command
 mouse_wait();
 //Tell the mouse we are sending a command
 outb(0x64, 0xD4);
 //Wait for the final part
 mouse_wait();
 //Finally write
 outb(0x60, a_write);
}

unsigned char mouse_read()
{
 //Get response from mouse
 mousewait();
 return inb(0x60);
}

 void mouseinit()
{
    outb(0x64,0xA8);
    mouse_wait();
    outb(0x64,0x20);
    unsigned char status_byte;
    mousewait();
    status_byte |= 0b10;
    mouse_wait();
    outb(0x64, 0x60);
    mouse_wait();
    outb(0x60, status_byte);
    mouse_write(0xF6);
    mouse_read();
    mouse_write(0xF4);
    mouse_read();
    //interruptHandlerRegister(12,&mouse_handler);
}

bool lookMouseOrKeyboard(){
  char bytes;
  int byte[4];
  switch (bytes){
    case 0:
      byte[0]=inb(0x64);
      bytes++;
      break;
    case 1:
      byte[1]=inb(0x64);
      bytes++;
      break;
    case 2:
      byte[2]=inb(0x64);
      bytes++;
      break;
    case 3:
      byte[3]=inb(0x64);
      bytes++;
    case 4:
      if (inb(0x64)==0x20)return 1;
      else return 0;
      break;
  }
  return 0;
}

	uint8 mouse_cycle=0;
	int8 mouse_byte[3];
  bool mouse_byteReady = false;
void mouse_updater(uint8_t data)
{
    if (mouse_byteReady) return;
  	switch(mouse_cycle)
  {
    case 0:
      if ((data & 0b00001000)==0) break;
      mouse_byte[0]=data;
      mouse_cycle++;
      break;
    case 1:
      mouse_byte[1]=data;
      mouse_cycle++;
      break;
    case 2:
      mouse_byte[2]=data;
      mouse_byteReady = true;
      mouse_cycle=0;
      break;
  }
}

void MousePacket(){
      if (!mouse_byteReady/*||!lookMouseOrKeyboard()*/) return;
        if (mouse_byte[0] & PS2Leftbutton) {
          KBmouse.mouseLeftClick = true;
          KBmouse.mouseClick = true;
        }else{
          KBmouse.mouseLeftClick = false;
          KBmouse.mouseClick = false;
        }
        mouse_byte[1]/=mouse_byte[2];
        mouse_byte[2]/=mouse_byte[2];
        if (!(mouse_byte[0] & PS2XSign)){
            KBmouse.x += mouse_byte[1];
            //write_serial('R');
            if (mouse_byte[0] & PS2XOverflow){
                KBmouse.x += 255;
            }
        }else{
            mouse_byte[1] = 256 - mouse_byte[1];
            KBmouse.x -= mouse_byte[1];
            //write_serial('L');
            if (mouse_byte[0] & PS2XOverflow){
                KBmouse.x -= 255;
            }
        }

        if (!(mouse_byte[0] & PS2YSign)){
            KBmouse.y -= mouse_byte[2];
            //write_serial('U');
            if (mouse_byte[0] & PS2YOverflow){
                KBmouse.y -= 255;
            }
        }else{
            mouse_byte[2] = 256 - mouse_byte[2];
            KBmouse.y += mouse_byte[2];
            //write_serial('D');
            if (mouse_byte[0] & PS2YOverflow){
                KBmouse.y += 255;
            }
        }

        if (KBmouse.x < 0) KBmouse.x = 0;
        if (KBmouse.x > 320) KBmouse.x = 320;
        KBmouse.velox = mouse_byte[1];
        if (KBmouse.y < 0) KBmouse.y = 0;
        if (KBmouse.y > 200) KBmouse.y = 200;
        KBmouse.veloy = mouse_byte[2];
        ctmouse(KBmouse.x, KBmouse.y);

        mouse_byteReady = false;
}