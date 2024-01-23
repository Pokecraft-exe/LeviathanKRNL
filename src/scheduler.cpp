#include "scheduler.hpp"

TaskManager::Task tasks[100] = {};
int tnum = 0;

namespace TaskManager {

Task::Task() {
    
}

void Task::start() {
    active = true;
}
void Task::join() {
    while (active);
    present = false;
    active = false;
}
void Task::stop(){
    active = 0;
}
void Task::avort(){
    present = false;
    active = false;
}
    
Task* Thread(void* target, int ms, void* args, int len) {
    tasks[tnum].args = args;
    tasks[tnum].alen = len;
    tasks[tnum].present = true;
    getState();
    memcpy(&tasks[tnum].cpu, &GlobalCPUState, sizeof(CPUState));
    tasks[tnum].cpu.rip = (uint64_t)target;
    tasks[tnum].cpu.rsp = (uint64_t)tasks[tnum].stack;
    tnum++;
}

}
