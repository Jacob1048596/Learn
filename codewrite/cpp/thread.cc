#include<stdio.h>
#include<pthread.h>
#include<iostream>
using namespace std;

#include"thread.h"
void Thread::start(){
    pthread_create(&thread_id_,NULL,thread_routine,this);
}
void *Thread::thread_routine(void * arg)
{
    Thread* thread=static_cast<Thread*>(arg);
    thread->run();
    if(thread->flag)
        delete thread;
}
void Thread::join(){
    pthread_join(thread_id_,NULL);
   // ::join(thread_id_,NULL);
}
