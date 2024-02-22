#include "scheduler.hpp"

int tnum = 0;

namespace TaskManager {

Task tasks[100] = {};

Task::Task() {
    present = true;
    active = false;
    _id = tnum;
}

void Task::start() {
    active = true;
}
void Task::join() {
    while (active);
    present = false;
    active = false;
}
void Task::stop() {
    active = false;
}
int Task::pid() {
    return _id;
}
bool Task::isStarted() {
    return active;
}
bool Task::isPresent() {
    return present;
}
void Task::abort(){
    present = false;
    active = false;
}
    
Task* Thread(void* target, void* args, int len) {
    tasks[tnum] = Task();

    tasks[tnum].cpu = (CPUState*)(tasks[tnum].stack + STACKSIZE - sizeof(CPUState));

    memset(tasks[tnum].cpu, 0, sizeof(CPUState));

    tasks[tnum].cpu->rip = (uint64_t)target;
    tasks[tnum].cpu->rflags = 0x202;
    tasks[tnum].cpu->cs = 0x08;
    tasks[tnum].cpu->rsp = (uint64_t)&tasks[tnum].stack;

    tnum++;
    return &tasks[tnum-1];
}

int taskNumber(){
    return tnum;
}

void dump() {
    using std::cout;
    cout << "there is " << tnum << " tasks\n";
    for (int i = 0; i < 100; i++) {
        if (tasks[i].isPresent()) {
            cout << "PID " << tasks[i].pid() << " ID: " << i << " active: " << (tasks[i].isStarted() ? "true" : "false") << '\n';
        }
    }
}
}

int currentTask = 0;
int tasksNotPresents = 0;

extern "C" CPUState* NextTask(CPUState* cpustate) {
    // save the last task's state
	TaskManager::tasks[currentTask].cpu = cpustate;

    currentTask++;
    while (currentTask <= tnum + 1) {
        if (TaskManager::tasks[currentTask].isStarted()) { // if next task is ready to be loaded
            //load next task
        	return TaskManager::tasks[currentTask].cpu;
        }
        currentTask++;
    }
    currentTask = 0;
    
    //load initial task
	return TaskManager::tasks[currentTask].cpu;
}
