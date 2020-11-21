#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>


int main()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(2580);
    inet_aton("192.168.1.20",&addr.sin_addr);

   int r=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
   if(r<0) {printf("服务器关闭\n");exit(1);}
    printf("连接成功\n");
    char buf[1024]={};
   while(fgets(buf,1024,stdin)!=NULL)
   {
       write(fd,buf,strlen(buf));
       memset(buf,0x00,sizeof(buf));
       int r=read(fd,buf,1024);
       if(r<=0)
       {
           printf("服务器关闭\n");
           close(fd);
           break;
       }
        printf("buf-->%s\n",buf);
        memset(buf,0x00,sizeof(buf));
   }

}