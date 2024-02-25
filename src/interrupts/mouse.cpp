#include "mouse.hpp"

namespace Mouse {

smouse pointer = {};

inline void wait(uint8_t a_type) //unsigned char
{
  uint32_t _time_out=100000; //unsigned int
  if(a_type==0)
  {
    while(_time_out--) //Data
    {
      if((Port8Bit(0x64).Read() & 1)==1)
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
      if((Port8Bit(0x64).Read() & 2)==0)
      {
        return;
      }
    }
    return;
  }
}

inline void write(uint8_t a_write) //unsigned char
{
  //Wait to be able to send a command
  wait(1);
  //Tell the mouse we are sending a command
  Port8Bit(0x64).Write(0xD4);
  //Wait for the final part
  wait(1);
  //Finally write
  Port8Bit(0x60).Write(0xD4);
}

uint8_t read()
{
  //Get's response from mouse
  wait(0);
  return Port8Bit(0x60).Read();
}

void install()
{
  uint8_t _status;  //unsigned char

  //Enable the auxiliary mouse device
  wait(1);
  Port8Bit(0x64).Write(0xA8);
 
  //Enable the interrupts
  wait(1);
  Port8Bit(0x64).Write(0x20);
  wait(0);
  _status=(Port8Bit(0x60).Read() | 2);
  wait(1);
  Port8Bit(0x64).Write(0x60);
  wait(1);
  Port8Bit(0x60).Write(_status);
 
  //Tell the mouse to use default settings
  write(0xF6);
  read();  //Acknowledge
 
  //Enable the mouse
  write(0xF4);
  read();  //Acknowledge
}

}