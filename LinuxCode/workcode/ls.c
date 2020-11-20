#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define ERR_EXIT(msg)\
        do{\
         printf("[%s][%d]%s:%s\n",__FILE__,__LINE__,msg,strerror(errno));\
         exit(EXIT_FAILURE);\
        }while(0)

int main()
{
    printf("befor execlp\n");
    if(execlp("ls","ls","-l",NULL)==-1) ERR_EXIT("execlp");
    printf("after execlp\n");
}
