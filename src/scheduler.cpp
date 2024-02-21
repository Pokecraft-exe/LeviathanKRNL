#include "scheduler.hpp"

int tnum = 0;

namespace TaskManager {

Task tasks[100] = {};

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
    active = false;
}
bool Task::started(){
    return active;
}
void Task::avort(){
    present = false;
    active = false;
}
    
Task* Thread(void* target, void* args, int len) {
    tasks[tnum].present = true;

    tasks[tnum].cpu = (CPUState*)(tasks[tnum].stack + 4096 - sizeof(CPUState));

    memset(tasks[tnum].cpu, 0, sizeof(CPUState));
    tasks[tnum].cpu->rip = (uint64_t)target;
    tasks[tnum].cpu->rflags = 0x202;
    tasks[tnum].cpu->cs = 0x08;
    /*tasks[tnum].cpu->ds = 0x10;
    tasks[tnum].cpu->es = 0x10;
    tasks[tnum].cpu->fs = 0x10;
    tasks[tnum].cpu->gs = 0x10;*/
    tasks[tnum].cpu->rsp = (uint64_t)&tasks[tnum].stack;

    tasks[tnum].stop();

    tnum++;
    return &tasks[tnum-1];
}

int taskNumber(){
    return tnum;
}
}

int currentTask = 0;
int tasksNotPresents = 0;

extern "C" CPUState* NextTask(CPUState* cpustate) {
    // save the last task's state
    int tnum_ = tnum + 1;
	TaskManager::tasks[currentTask].cpu = cpustate;

    currentTask++;
    while (currentTask <= tnum_) {
        if (TaskManager::tasks[currentTask].started()) { // if next task is ready to be loaded
            //load next task
        	return TaskManager::tasks[currentTask].cpu;
        }
        currentTask++;
    }
    currentTask = 0;
    
    //load initial task
	return TaskManager::tasks[currentTask].cpu;
}
