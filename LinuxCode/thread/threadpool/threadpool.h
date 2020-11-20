#ifndef _THREADPOOL_H__
#define _THREADPOOL_H__

#include<pthread.h>
//任务节点
typedef struct task
{
    /* data */
    void *(*run)(void *arg);//任务的回调函数
    void* arg;//回调函数的参数
    struct task *next;
}task_t;

//线程池结构体

typedef struct threadpool{
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    task_t* first;  //任务队列队头
    task_t*last;    //任务队列队尾指针
    int counter;    //线程池中当前有多少线程
    int idle;       //空闲线程个数
    int max_thead;  //线程池中线程的阈值
    int quit;       //线程池销毁标志，默认是0；
}threadpool_t;

//初始化线程池
void threadpool_init(threadpool_t *pool,int max_thread);
//往线程池中添加任务
void threadpool_add_task(threadpool_t*pool,void*(*run)(void*),void *arg);
//销毁线程池
void threapool_destory(threadpool_t *pool);
#endif // !_THREADPOOL_H__