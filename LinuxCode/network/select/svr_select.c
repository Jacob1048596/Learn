#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>

int tcp_init()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);
    int op=1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&op,sizeof(op));

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(2580);
    //addr.sin_addr.s_addr=htonl(INADDR_ANY);
    inet_aton("192.168.1.20",&addr.sin_addr);
    int r=bind(fd,(struct sockaddr*)&addr,sizeof(addr));
    if(r==-1) perror("bind"),exit(1);
     printf("绑定成功\n");
    if( (r=listen(fd,10))==-1)
        perror("listen"),exit(1);
    
    return fd;
}

int main()
{
    int lfd=tcp_init();

    int clients[FD_SETSIZE];

    fd_set rset,allset;
    int maxfd,i;

    for(i=0;i<FD_SETSIZE;i++) clients[i]=-1; //client初始化为-1

     FD_ZERO(&rset);
     FD_ZERO(&allset);
     FD_SET(lfd,&allset);
     maxfd=lfd;
     for(;;)
     {
         rset=allset;
         int nready=select(maxfd+1,&rset,NULL,NULL,NULL);
         if(nready<=0) continue;

         if(FD_ISSET(lfd,&rset))
         {
             int cfd=accept(lfd,NULL,NULL);
             for(i=0;i<FD_SETSIZE;i++)
             {
                 if(clients[i]==-1)
                 {
                     clients[i]=cfd;
                     maxfd=maxfd>cfd?maxfd:cfd;
                     break;
                 }
             }
             if(i==FD_SETSIZE)
             {
                 printf("too many client\n");
                 exit(0);
             }
             FD_SET(cfd,&allset);
             if(--nready<=0) continue;
         }

         for(i=0;i<FD_SETSIZE;i++)
         {
             int fd=clients[i];
             if(fd==-1) continue;
             if(FD_ISSET(fd,&rset))
             {
                 char buf[1024]={};
                 int r=read(fd,buf,1024);

                 if(r<=0)
                 {
                    clients[i]=-1;
                    close(fd);
                    FD_CLR(fd,&allset);
                 }else{
                     //process();
                     write(fd,buf,r);
                 }

             }
             if(--nready<=0) break;
         }
     }
    
}