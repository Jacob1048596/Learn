#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>
#include<sys/epoll.h>

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
    int epfd=epoll_create(1);
    struct epoll_event ev,evs[1024];

    ev.events=EPOLLIN;
    ev.data.fd=lfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&ev);
    for(;;)
    {
        int r=epoll_wait(epfd,evs,104,-1);
        for(int i=0;i<r;i++)
        {
            int cfd=evs[i].data.fd;
            if(cfd==lfd)
            {
            
                int nfd=accept(lfd,NULL,NULL);
                ev.events=EPOLLIN;
                ev.data.fd=nfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,nfd,&ev);//普通节点加入红黑树
            }else{
                char buf[1024]={};
                int rd=read(cfd,buf,1024);
                if(rd<=0)
                {
                    epoll_ctl(epfd,EPOLL_CTL_DEL,cfd,NULL);//当对方关闭，从红黑树中删除
                    close(cfd);
                }else{
                    write(cfd,buf,rd);
                }

            }
        }
    }


}