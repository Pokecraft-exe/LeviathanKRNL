#pragma once
#include "IO.h"
#include "IDT.h"

namespace TaskManager {

class Task{
public:
    bool active = 0;
    bool present = 0;
    uint8_t stack[4096];
    void* args;
    int alen;
    CPUState cpu;
    Task();
    void start();
    void join();
    void stop();
    void avort();
};

Task* Thread(void* target, void* args, int len);

}


extern TaskManager::Task tasks[];
