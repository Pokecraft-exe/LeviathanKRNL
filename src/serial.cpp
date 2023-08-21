#include "H/serial.h"

void s_outb(unsigned short port, unsigned char val){
  asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

unsigned char s_inb(unsigned short port){
  unsigned char returnVal;
  asm volatile ("inb %1, %0"
  : "=a"(returnVal)
  : "Nd"(port));
  return returnVal;
}

int init_serial() {
   s_outb(PORT + 1, 0x00);    // Disable all interrupts
   s_outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   s_outb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   s_outb(PORT + 1, 0x00);    //                  (hi byte)
   s_outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
   s_outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   s_outb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
   s_outb(PORT + 4, 0x1E);    // Set in loopback mode, test the serial chip
   s_outb(PORT + 0, 0xAE);    // Test serial chip (send byte 0xAE and check if serial returns same byte)
 
   // Check if serial is faulty (i.e: not same byte as sent)
   if(s_inb(PORT + 0) != 0xAE) {
      return 1;
   }
 
   // If serial is not faulty set it in normal operation mode
   // (not-loopback with IRQs enabled and OUT#1 and OUT#2 bits enabled)
   s_outb(PORT + 4, 0x0F);
   return 0;
}

int is_transmit_empty() {
   return s_inb(PORT + 5) & 0x20;
}
 
void write_serial(char a) {
   while (is_transmit_empty() == 0);
 
   s_outb(PORT,a);
}

int serial_received() {
   return s_inb(PORT + 5) & 1;
}
 
char read_serial() {
   while (serial_received() == 0);
 
   return s_inb(PORT);
}

void puts(const char* a){
  int i = 0;
  for(i = 0; a[i] != 0; i++)
  {
    write_serial(a[i]);
  }
}

void debug(const char* Message, bool Status){
   puts(Message);
   puts("[");
   if (Status){
      puts(SERIALGREEN);
      puts("OK");
      puts(SERIALBLUE);
      puts("]\n\r");
   }else{
      puts(SERIALRED);
      puts("ERROR");
      puts(SERIALBLUE);
      puts("]\n\r");
   }
}
