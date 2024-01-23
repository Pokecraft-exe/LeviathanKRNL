#include "scheduler.hpp"

Task tasks[100] = {0};
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
    
Task* Thread(void* target, void* args, int len) {
    int i;
    for (i = 0; i < tnum; i++) {
        if (tasks[i].present == false) {
            
        }
    }
    if (i == tnum - 1) {
        tnum++;
    }
}

}
