#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>

void*r1(void*args)
{
    int cfd=*(int*)args;
    char buf[1024]={};
    while(fgets(buf,1024,stdin)!=NULL)
    {
        write(cfd,buf,strlen(buf));
        memset(buf,0x00,sizeof(buf));
    }
}
void*r2(void*args)
{
    int cfd=*(int*)args;
    char buf[1024]={};
    while(1)
    {
        memset(buf,0x00,sizeof(buf));
        int r=read(cfd,buf,1024);
        if(r<=0)
        {
            printf("server close\n");
            exit(0);
        }
        printf("::%s",buf);
        fflush(stdout);
    }
}

int main()
{
    int cfd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(2580);
    //addr.sin_addr.s_addr=htonl(INADDR_ANY);
    inet_aton("192.168.1.20",&addr.sin_addr);
    int r=connect(cfd,(struct sockaddr*)&addr,sizeof(addr));

    pthread_t t1,t2;
    int *p=malloc(sizeof(int));
    *p=cfd;
    pthread_create(&t1,NULL,r1,p);   
    pthread_create(&t2,NULL,r2,p);   

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    free(p);
}