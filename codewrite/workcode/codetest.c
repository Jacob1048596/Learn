#include<stdio.h>
#define _GNU_SOURCE
#define _USE_GNU
#include<sched.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid;
    if((pid==fork())==0)
    {
        cpu_set_t cup_affinity;
        CPU_ZERO(&cup_affinity);
        CPU_SET(0,&cup_affinity);

        sched_setaffinity(0,sizeof(cpu_set_t),&cup_affinity); 
        while(1)
        {
            printf("child\n");
            sleep(1);
        }
    }else
    {
        cpu_set_t cup_affinity;
        CPU_ZERO(&cup_affinity);
        CPU_SET(1,&cup_affinity);

        sched_setaffinity(0,sizeof(cpu_set_t),&cup_affinity); 
         while(1)
        {
            printf("parent\n");
            sleep(1);
        }
    }
    
}