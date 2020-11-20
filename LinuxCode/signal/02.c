#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<signal.h>
#include<sys/ioctl.h>
#include<termio.h>
void handler()
{
    printf("time out\n");
}
int main(int argc, char const *argv[])
{
    // if(argc!=2)
    // {
    //     printf("usage:%s pid\n",argv[0]);
    //     exit(1);
    // }
    // int pid=atoi(argv[1]);
    // kill(pid,SIGKILL);
    signal(SIGALRM,handler);
    alarm(20);

    srand(time(NULL));
    for(;;)
    {
        int left=rand()%10;
        int right=rand()%10;
        int ret;
        printf("%d+%d=",left,right);
        scanf("%d",ret);
        if(ret==left+right)
        {

        }else
        {
            /* code */
        }
        
    }
    
    return 0;
}

