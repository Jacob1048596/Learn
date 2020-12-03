#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>
 
 #define PRODUCE 1
 #define CUSTOME 3

pthread_t tid[PRODUCE+CUSTOME];
pthread_cond_t cond;
pthread_mutex_t mutex;

int num=0;

void* produce(void* arg)
{
    int id =*(int*)arg;
     free(arg);
    while(1)
    {
        sleep(1);
        pthread_mutex_lock(&mutex);
        printf("[%d]开始生产，编号为[%d]\n",id,num+1);
        num++;
        sleep(rand()%3);
        printf("[%d]生产结束,编号为[%d]\n",id,num);
        pthread_cond_signal(&cond);     //通知消费者进行消费//唤醒至少一个
        pthread_mutex_unlock(&mutex);
        sleep(rand()%2);
    }
   
}
void* custome(void*arg)
{
     int id =*(int*)arg;
     free(arg);
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(num<=0)
        {
            printf("[%d]消费者线程等待产品\n",id);
            pthread_cond_wait(&cond,&mutex);
            printf("[%d]消费者线程等到产品,返回\n",id);
        }
        printf("[%d]开始消费，编号为[%d]\n",id,num);
        num--;
        sleep(rand()%3);
        printf("[%d]消费结束,编号为[%d]\n",id,num+1);
        pthread_mutex_unlock(&mutex);
        sleep(rand()%2);
    }
}
 int main()
 {
     int i;

     srand(getppid());
     pthread_cond_init(&cond,NULL);
     pthread_mutex_init(&mutex,NULL);
     for(i=0;i<PRODUCE;i++)
     {
         int *p=malloc(sizeof(int));
         *p =i;
         pthread_create(&tid[i],NULL,produce,(void*)p);
     }
     for(i=0;i<CUSTOME;i++)
     {
         int *p=malloc(sizeof(int));
         *p =i;
         pthread_create(&tid[i+PRODUCE],NULL,custome,(void*)p);
     }
     for(i=0;i<PRODUCE+CUSTOME;i++)
     {
         pthread_join(tid[i],NULL);
     }

     pthread_cond_destroy(&cond);
     pthread_mutex_destroy(&mutex);
 }