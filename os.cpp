#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void TaskA(){
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("TaskA : %d\n",i);
        fflush(stdout);
    }
}

void TaskB(){
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("TaskB : %d\n",i);
        fflush(stdout);
    }
}

int main(){
    thread t1(TaskA);
    thread t2(TaskB);

    t1.join();
    t2.join();

    return 0;
}