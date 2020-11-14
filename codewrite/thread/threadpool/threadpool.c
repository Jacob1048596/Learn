#include"threadpool.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<errno.h>

//初始化线程池
void threadpool_init(threadpool_t *pool,int max_thread)
{
    pthread_cond_init(&pool->cond,NULL);
    pthread_mutex_init(&pool->mutex,NULL);
    pool->first=NULL;
    pool->last=NULL;
    pool->counter=0;
    pool->idle=0;
    pool->max_thead=max_thread;
    pool->quit=0;
}

void *routine(void *arg)
{
    threadpool_t *pool=(threadpool_t*)arg;
    int timeout=0;
    printf("%ld thread creat\n",pthread_self());
    while(1)
    {
        timeout=0;
        pthread_mutex_lock(&pool->mutex);
        pool->idle++;
        while(pool->first==NULL&&pool->quit==0)
        {
            struct timespec abstime;
            clock_gettime(CLOCK_REALTIME,&abstime);
            abstime.tv_sec+=5;

            int ret=pthread_cond_timedwait(&pool->cond,&pool->mutex,&abstime);
            if(ret==ETIMEDOUT)
            {
                timeout=1;
                printf("%ld thread timeout\n",pthread_self());
                break;
            }
        }
        pool->idle--;

        if(pool->first!=NULL)
        {
            task_t *tmp=pool->first;
            pool->first=tmp->next;
            pthread_mutex_unlock(&pool->mutex);
            tmp->run(tmp->arg);
            free(tmp);
            pthread_mutex_lock(&pool->mutex);
        }

        if(pool->first==NULL&&timeout==1)
        {
            pool->counter--;
            pthread_mutex_unlock(&pool->mutex);
            break;
        }
        if(pool->first==NULL&&pool->quit==1)
        {
            pool->counter--;
            if(pool->counter==0)//最后一个退出的线程，通知destory中的wait
                {
                    pthread_cond_signal(&pool->cond);
                }
            pthread_mutex_unlock(&pool->mutex);
            break;
        }
        pthread_mutex_unlock(&pool->mutex);
    }
    printf("%ld thread exit\n",pthread_self());
}
//往线程池中添加任务
void threadpool_add_task(threadpool_t*pool,void *(*run)(void*),void *arg)
{
    task_t *new_task=malloc(sizeof(task_t));
    new_task->run=run;
    new_task->arg=arg;

    //往任务队列中添加任务
    pthread_mutex_lock(&pool->mutex);
    if(pool->first==NULL)
    {
        pool->first=new_task;
    }else
    {
        pool->last->next=new_task;
    }
    pool->last=new_task;
    

    //如果有空闲线程，直接唤醒，执行当前任务
    if(pool->idle>0)
    {
        pthread_cond_signal(&pool->cond);
    }else if (pool->counter<pool->max_thead)
    { //如果没有空闲线程,达到上限，创建新线程
        pthread_t tid;
        pthread_create(&tid,NULL,routine,pool);
        pool->counter++;
    }
    pthread_mutex_unlock(&pool->mutex);
   
}
//销毁线程池
void threapool_destory(threadpool_t *pool)
{
    if(pool->quit==1) return;

    pthread_mutex_lock(&pool->mutex);
    pool->quit=1;
    printf("线程池开始销毁\n");
    if(pool->counter>0)
    {
        //当线程池中空闲线程大于0
        //pthread_cond_broadcast唤醒所以阻塞在timedwait的线程
        if(pool->idle>0)
            pthread_cond_broadcast(&pool->cond);
        //如果销毁线程池时，线程池中的线程正在执行任务
        //不会受到broadcast的通知
        while(pool->counter>0)
            pthread_cond_wait(&pool->cond,&pool->mutex); 
    }
    pthread_mutex_unlock(&pool->mutex);
    pthread_cond_destroy(&pool->cond);
    pthread_mutex_destroy(&pool->mutex);
    printf("线程池销毁完毕\n");
}