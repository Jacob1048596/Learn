#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<signal.h>
#include<sys/ioctl.h>
#include<termio.h>
void handler1(int n)
{
    printf("hahahahaha:%d\n",n);

}
void handler(int n)
{
    if(n==SIGINT)
    {
        printf("catch %d",n);
        sleep(1);
        printf("handel end\n");
      
    }else if(n==SIGWINCH)
        {
            printf("%s",strsignal(n));
        }
}
 typedef void (*handler_t)(int s);
int main()
{
//     handler_t old=NULL;
//     if((old=signal(SIGINT,SIG_IGN))==SIG_ERR)
//     perror("signal"),exit(1);
// #if 0
//     while (1)
//     {
//         /* code */
//         if(getchar()=='\n')
//         break;
      
//     }
//     signal(SIGINT,old);
//     #endif
//     while(1)
//     {
//          printf(".");
//         fflush(stdout);
//         sleep(1);
//     }
signal(SIGINT,handler);
signal(SIGWINCH,handler);
for(;;)
{
    struct winsize w;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&w);
    printf("row=%d,col=%d\n",w.ws_row,w.ws_col);
    fflush(stdout);
    sleep(1);
}

  
}