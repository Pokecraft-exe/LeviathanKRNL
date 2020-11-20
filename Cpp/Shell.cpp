#include "H/printf.h"
#include "H/typedefs.h"

void Shell(){
    string strr;
//    __asm__(

//"pop strr"
//"mov di, strr"
//"keyloop:"
//        "mov ah, 0x00"
//        "int 0x16"
//        "mov ah, 0x0e"
//        "cmp al, 0xD"
//        "je doneScanf"
//        "mov [di], al"
//        "inc [di]"
//        "jmp keyloop"
//"doneScanf:"
//        "mov byte [di], 0"
//        "mov al, strr"
//"end_program:"
//        "cli"
//        "hlt"

//    );
    if (strr == "hello") printf("command hello");
    else printf("command not found");
}
void scanf(string address){
  while 1{
    switch (chrcode){
      case 13:
        *address = *address + '0';
        return 0;
        break;
      default:
        *address = *address + chrcode;
    }
  }
}