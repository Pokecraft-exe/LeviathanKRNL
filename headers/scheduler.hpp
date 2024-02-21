#pragma once
#include "IO.h"
#include "IDT.h"

extern "C" void Schedule();

namespace TaskManager {

class Task{
    bool active = 0;
    void* args;
    int alen;
public:
    bool present = 0;
    CPUState* cpu;
    uint8_t stack[4096];
    Task();
    void start();
    void join();
    void stop();
    void avort();
    bool started();
};

Task* Thread(void* target, void* args, int len);


extern Task tasks[];
int taskNumber();

}
