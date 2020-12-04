#include "H/typedefs.h"

extern const char Text[];

extern "C" void _start(){
    asm("db 'h'");
    return;
}
