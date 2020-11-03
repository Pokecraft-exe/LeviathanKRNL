ReadFromCMOS (unsigned char array [])
{
   unsigned char tvalue, index;
 
   for(index = 0; index < 128; index++)
   {
      _asm
      {
         cli             /* Disable interrupts*/
         mov al, index   /* Move index address*/
         /* since the 0x80 bit of al is not set, NMI is active */
         out 0x70,al     /* Copy address to CMOS register*/
         /* some kind of real delay here is probably best */
         in al,0x71      /* Fetch 1 byte to al*/
         sti             /* Enable interrupts*/
         mov tvalue,al
       }
 
       array[index] = tvalue;
   }
}

WriteTOCMOS(unsigned char array[])
{
   unsigned char index;
 
   for(index = 0; index < 128; index++)
   {
      unsigned char tvalue = array[index];
      _asm
      {
         cli             /* Clear interrupts*/
         mov al,index    /* move index address*/
         out 0x70,al     /* copy address to CMOS register*/
         /* some kind of real delay here is probably best */
         mov al,tvalue   /* move value to al*/
         out 0x71,al     /* write 1 byte to CMOS*/
         sti             /* Enable interrupts*/
      }
   }
}
