#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<pthread.h>

typedef struct cilent
{
    int cfd;
    char nickname[32];
}client_t;
typedef struct node
{
    client_t c;
    struct node* next;
    struct node* prev;
}node_t;

node_t *head=NULL;

void list_int(void)
{
    node_t *p=malloc(sizeof(mode_t));
    p->next=p->prev=p;
    head=p;
}

void list_insert(client_t *pc)
{
    node_t *p=malloc(sizeof(mode_t));
    p->c=*pc;
    p->next=head->next;
    p->prev=head;
    head->next->prev=p;
    head->next=p;
}

void list_erase(int cfd)
{
    node_t *p=head->next;

    while(p!=head)
    {
        if(p->c.cfd==cfd)
        {
            p->next->prev=p->prev;
            p->prev->next=p->next;
            free(p);
            break;
        }
        p=p->next;
    }
}

int list_lenth()
{
    node_t *p=head->next;
    int i=0;
    while(p!=head)
    {
        i++;
        p=p->next;
    }
    return i;
}

void send_all(char *msg)
{
    node_t *p=head->next;

    while(p!=head)
    {
        write(p->c.cfd,msg,strlen(msg));
        p=p->next;
    }
}

int tcp_init()
{
    int fd=socket(AF_INET,SOCK_STREAM,0);
    int op=1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&op,sizeof(op));//timewait状态时服务器可以重启

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

void* process(void* args)
{
    int cfd=*(int*)args;
    free(args);

    char buf[1024];
    sprintf(buf,"欢迎来到聊天室\n");
    write(cfd,buf,strlen(buf));

    sprintf(buf,"昵称:");
    write(cfd,buf,strlen(buf));
    char nickname[100]={};
    read(cfd,nickname,100);
    nickname[strlen(nickname)-1]=0;

    memset(buf,0x00,sizeof(buf));
    sprintf(buf,"[%s]上线了\n",nickname);
    printf("%s",buf);
    fflush(stdout);
    printf("success\n");
    
    send_all(buf);//段错误，原因未知

    printf("success\n");
    client_t cli;
    cli.cfd=cfd;
    memset(buf,0x00,sizeof(buf));
    sprintf(cli.nickname,"%s",nickname);
    list_insert(&cli);
    while(1)
    {
        memset(buf,0x00,sizeof(buf));
        int r=read(cfd,buf,1024);
        if(r<=0)
        {
            sprintf(buf,"%s 下线\n",cli.nickname);
            send_all(buf);
            break;
        }else{
            char tmp[1024]={};
            sprintf(tmp,"%s:%s",nickname,buf);
            send_all(buf);
        }
    }

    list_erase(cfd);
    printf("欢迎下次来聊天\n");
    close(cfd);
}
int main()
{
    list_int();
    int lfd=tcp_init();
   
    for(;;)
    {
         int cfd=accept(lfd,NULL,NULL);
         if(cfd<=0) continue;
         pthread_t tid;
         int*p=malloc(sizeof(int));
         *p=cfd;
         pthread_create(&tid,NULL,process,p);
         pthread_detach(tid);
    }
}