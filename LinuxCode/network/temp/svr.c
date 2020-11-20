#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include"public.h"

int tcp_init()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);
    int op=1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&op,sizeof(op));

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(2580);
    addr.sin_addr.s_addr=htonl(INADDR_ANY);
    //inet_aton("192.168.1.20",&addr.sin_addr);
    int r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    if(r==-1) perror("bind"),exit(1);
     printf("绑定成功\n");
    if( (r=listen(fd,SOMAXCONN))==-1)
        perror("listen"),exit(1);
    printf("设置listen成功\n");
    return fd;
}
int main()
{
    int lfd=tcp_init();
    int cfd=accept(lfd,NULL,NULL);
    printf("连接成功\n");
    message_t msg;
    while (1)
    {
        memset(&msg,0x00,sizeof(msg));
        if(readn(cfd,&msg.len,sizeof(int))<=0)  
            printf("client close\n");
        int len=ntohl(msg.len);
        if(readn(cfd,msg.cont,len)<=0)
        {
            printf("client close\n");
        }

        if(strncmp(msg.cont,"exit",4)==0)
            exit(0);

        writen(cfd,&msg.len,sizeof(int));
        writen(cfd,msg.cont,len);
        /* code */
    }
    
}