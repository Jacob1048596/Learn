#ifndef _THREAD_H__
#define _THREAD_H__

#include<iostream>
#include<pthread.h>
using namespace std;
class Thread{
public:
    Thread(bool flag=true){cout<<"thread creat"<<endl;}
    virtual ~Thread(){cout<<"thread delete"<<endl;}
    void start();
    void join();
private:
    static void *thread_routine(void* arg);
    pthread_t thread_id_;
    virtual void run()=0;
    static bool flag; 
};

#endif 