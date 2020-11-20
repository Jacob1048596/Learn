#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include"public.h"
#include<pthread.h>

void handler(int s)
{
    printf("receive s %d\n",s);
    printf("pipe bresk\n");
}

void* r2(void* args)
{
    message_t msg;
    while(1)
    {
        int fd=*(int*) args;
        memset(&msg,0x00,sizeof(msg));
        if(readn(fd,&msg.len,sizeof(int))<=0) 
        {
            printf("server close\n");
            break;
        }
        int len=ntohl(msg.len);
        printf("msg len:%d\n",len);
        if(readn(fd,&msg.cont,len)<=0)
        {
            printf("client close\n");
            break;
        } 
        printf("==> %s\n",msg.cont);
    }
    exit(0);
}
void* r1(void* args)
{
      message_t msg;
    int fd=*(int*) args;

    while(fgets(msg.cont,1024,stdin)!=NULL)
    {
        msg.len=htonl(strlen(msg.cont));
        writen(fd,&msg.len,sizeof(int));//发送定长包头
        writen(fd,&msg.cont,strlen(msg.cont));//发送边长包体
        
        memset(&msg,0x00,sizeof(msg));
    }
}
int main()
{
    struct sigaction act;
    act.sa_handler=handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;
    sigaction(SIGPIPE,&act,NULL);

    int fd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(2580);
    inet_aton("192.168.1.20",&addr.sin_addr);
    int r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
    if(r==-1) {perror("connect"),exit(1);}
    printf("连接成功\n");
    
    pthread_t tid1,tid2;

    int *p=malloc(sizeof(int));
    *p=fd;
    pthread_create(&tid1,NULL,r1,p);
    pthread_create(&tid2,NULL,r2,p);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    free(p);
}