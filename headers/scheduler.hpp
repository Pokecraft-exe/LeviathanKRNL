#pragma once
#include "IO.h"
#include "IDT.h"
#include "typedefs.h"

namespace TaskManager {

class Task{
private:
    bool active = 0;
    bool present = 0;
    uint8_t stack[4096];
    void* target;
    void* args;
    int alen;
    CpuState* cpu;
    Task();
    void start();
    void join();
    void stop();
}

bool Thread(void* target, void* args, int len);

}
