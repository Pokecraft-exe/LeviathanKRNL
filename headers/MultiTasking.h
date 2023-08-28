#pragma once
#include "IO.h"
#include "IDT.h"
#include "typedefs.h"

class Task{
private:
    uint8_t stack[4096];
    CpuState* cpu;
    Task();
}
