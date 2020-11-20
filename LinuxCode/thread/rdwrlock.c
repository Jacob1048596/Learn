#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<errno.h>

pthread_rwlock_t lock;
int g_data;
void *read_r(void* arg)
{
    while (1)
    {
        /* code */
        pthread_rwlock_rdlock(&lock);
        printf("Thread id=%lx,g_data=%d\n",pthread_self(),g_data);
        
        pthread_rwlock_unlock(&lock);
        sleep(1);
    }
    
}
void *write_r(void *arg)
{
    while (1)
    {
        /* code */
        pthread_rwlock_wrlock(&lock);
        g_data++;
        pthread_rwlock_unlock(&lock);
    }
}
int main()
{
    pthread_rwlock_init(&lock,NULL);
    pthread_t r1,r2,w1;
    pthread_create(&r1,NULL,read_r,NULL);
    pthread_create(&r2,NULL,read_r,NULL);
    pthread_create(&w1,NULL,write_r,NULL);

    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(w1,NULL);
    
    pthread_rwlock_destroy(&lock);
    return 0;
}