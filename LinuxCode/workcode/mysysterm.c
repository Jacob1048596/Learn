#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int mysystem(const char* cmd)
{
    pid_t pid;
    if((pid==fork())==-1)
        exit(127);
    if(pid==0)
    {
      if(  execlp("/bin/sh","hahaha","-c",cmd,NULL)==-1)
      {
          exit(1);
      }
    }
    //子进程走不到这里
    int status;
     waitpid(pid,&status,WNOHANG);
        
    if (WIFEXITED(status))//子进程正常退出返回真
    {
        return WEXITSTATUS(status);//获取子进程的退出码
    }
    return -1;//子进程不是正常退出返回-1
}
int main()
{
    printf("befor system\n");
   int ret= mysystem("ls -l") ;
   //system("ls -l");
   
    printf("%d,after system\n",ret);
}