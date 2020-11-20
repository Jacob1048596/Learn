#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<errno.h>
#define ERR_EXIT(msg)\
        do{\
         printf("[%s][%d]%s:%s\n",__FILE__,__LINE__,msg,strerror(errno));\
         exit(EXIT_FAILURE);\
        }while(0)
int  getInput(char *buf)
{
 memset(buf,0x00,sizeof(buf));
 
       if(scanf("%[^\n]%*c",buf)!=1)
       {
           int c;
           do c=getchar();
           while(c!='\n');
       }
 return strlen(buf);
}
void doAction(int argc,char *argv[])
{
    pid_t pid;
    switch(pid=fork())
    {
        case -1:
            printf("当前系统错误，维护ing。。。");
            return ;
            //ERR_EXIT("Fork");
        break;
        case 0:
        {
            int ret=execvp(argv[0],argv);//子进程中庸argv[0]
            printf("[%s]:command not fount\n",argv[0]);
            exit(1);
        }
        break;
        default:
        {
            int status;
             waitpid(pid,&status,0);
         }  
        break;
    }
}
void doParse(char* buf)
{
    int argc=0;
    char* argv[10]={};
    #define OUT 0
    #define IN 1
    int status=OUT;
    int i;
    for(i=0;buf[i]!='\0';i++)
    {
        if(status==OUT&&!isspace(buf[i]))
        {
            argv[argc]=buf+i;
            argc++;
            status=IN;
        }
        if(status==IN&&isspace(buf[i]))
        {
            status=OUT;
            buf[i]='\0';
        }
    }
    argv[argc]=NULL;
    doAction(argc,argv);
    for(int i=0;i<argc;i++)
    {
        printf("[%s] ",argv[i]);
    }
}
int main()
{
    char buf[512];
    while(1)
    {
        printf("[MyShell]#");
      if(getInput(buf)==0) continue; //读取一行数据
       doParse(buf);//解析数据
    }
}