#pragma once
#include "IO.h"
#include "IDT.h"

#define STACKSIZE 4096//4084

namespace TaskManager {

class Task{
    bool active;
    bool present;
    uint16_t _id;
    uint8_t ms;
public:
    CPUState* cpu;
    uint8_t stack[STACKSIZE];
    Task();
    int pid();
    void start();
    void join();
    void stop();
    void abort();
    bool isStarted();
    bool isPresent();
};

Task* Thread(void* target, void* args, int len);

void dump();

extern Task tasks[];
int taskNumber();

}
