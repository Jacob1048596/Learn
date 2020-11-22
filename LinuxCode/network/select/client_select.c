#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>

int main()
{
    int cfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(2580);
    inet_aton("192.168.1.20",&addr.sin_addr);
    int r=connect(cfd,(struct sockaddr*)&addr,sizeof(addr));
     if(r==-1) {perror("connect"),exit(1);}
    printf("连接成功\n");

    int key_fd=fileno(stdin);
    int maxfd=cfd>key_fd?cfd:key_fd;

    fd_set rset;
    FD_ZERO(&rset);

    char buf[1024]={};
    for(;;)
    {
        FD_SET(cfd,&rset);
        FD_SET(key_fd,&rset);
        int ready=select(maxfd+1,&rset,NULL,NULL,NULL);
        if(ready<=0) continue;
        if(FD_ISSET(cfd,&rset))
        {
            memset(buf,0x00,sizeof(buf));
            int r=read(cfd,buf,1024);
            if(r<=0)
            {
                printf("sever close\n");
                break;
            }
            printf("=>%s\n",buf);
        }
        if(FD_ISSET(key_fd,&rset))
        {
            memset(buf,0x00,sizeof(buf));
            if(fgets(buf,1024,stdin)==NULL)
            {
                break;
            }
            printf("writ:%s\n",buf);
            write(cfd,buf,strlen(buf));
        }
    }
}