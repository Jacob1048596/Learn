#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>

int g_ticket=100;
pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;

void* route1(void* arg)
{

pthread_mutex_lock(&mutex_a);
sleep(2);
int ret;
if((ret=pthread_mutex_trylock(&mutex_b))!=0)
{
    printf("1,Tryock:%s\n",strerror(ret));
    return NULL;
}
//pthread_mutex_lock(&mutex_b);

printf("haha thread 1\n");
pthread_mutex_unlock(&mutex_b);
pthread_mutex_unlock(&mutex_a);
}
void* route2(void* arg)
{

pthread_mutex_lock(&mutex_b);
sleep(2);
int ret;
if((ret=pthread_mutex_trylock(&mutex_a))!=0)
{
    printf("2,Tryock:%s\n",strerror(ret));
    return NULL;
}

printf("haha thread 2\n");
pthread_mutex_unlock(&mutex_a);
pthread_mutex_unlock(&mutex_b);
}
int main()
{
    pthread_t t1,t2,t3,t4;
    pthread_mutex_init(&mutex_a,NULL);
    pthread_mutex_init(&mutex_b,NULL);

    pthread_create(&t1,NULL,route1,NULL);
    pthread_create(&t2,NULL,route2,NULL);
    // pthread_create(&t3,NULL,route,"thread3");
    // pthread_create(&t4,NULL,route,"thread4");
   
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    // pthread_join(t3,NULL);
    // pthread_join(t4,NULL);

    pthread_mutex_destroy(&mutex_a);
    pthread_mutex_destroy(&mutex_b);
}