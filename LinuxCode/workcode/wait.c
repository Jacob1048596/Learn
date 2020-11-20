#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    if((pid=fork())==0)
    {
        for(int i=0;i<10;i++)
        {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
    }else{
        wait(NULL);
        printf("Wait return\n");
    }
}
