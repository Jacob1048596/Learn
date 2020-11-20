#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<signal.h>
#include<sys/ioctl.h>
#include<termio.h>
void handler(int s)
{
    printf("recieve %d\n",s);
    sleep(2);
    printf("receieve complete \n");
}
int main()
{
    int i;
    //srand(time(NULL));
    sigset_t set, old_set,pend;

    signal(SIGINT,handler);

    sigemptyset(&set);
    sigemptyset(&old_set);


    sigaddset(&set,SIGINT);

    sigprocmask(SIG_BLOCK,&set,&old_set);
    for(i=0;i<5;i++)
    {
        printf("copy %d\n",i+1);
        sleep(2);
        printf("copy complete %d\n",i+1);

        sigemptyset(&pend);
        sigpending(&pend);
        
        if(sigismember(&pend,SIGINT)==1)
        {
            printf("have signal waiting\n");
            sigset_t tmp;
            sigemptyset(&tmp);
            sigsuspend(&tmp);
        }
    }
    sigprocmask(SIG_SETMASK,&old_set,NULL);

    printf("man finish\n");
}