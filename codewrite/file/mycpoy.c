#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
//usage : ./mycopy src dst
int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        fprintf(stderr,"usage:%s src dst\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd_src=open(argv[1],O_RDONLY);//只读方式打卡源文件
    if(fd_src==-1)
    {
         fprintf(stderr,"open(%s):%s \n",argv[1],strerror(errno));//打开失败显示错误信息并退出
        exit(EXIT_FAILURE);
    }
    int fd_dst=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);//只写方式读取目标文件，如没有测创建文件
    if(fd_dst==-1)
    {
         fprintf(stderr,"open(%s):%s \n",argv[2],strerror(errno));//打开失败显示错误信息并退出
         close(fd_src);
        exit(EXIT_FAILURE);
    }
    char buf[1024];
    while(1)
    {
        memset(buf,0x00,sizeof(buf));
        int ret=read(fd_src,buf,1024);//读
        if(ret==-1)
        {
           fprintf(stderr,"read(%s):%s \n",argv[1],strerror(errno));
           break;
        }else if(ret==0)//读完文件返回值为0；
        {
            break;
        }
        int wrt=write(fd_dst,buf,ret);//写
        if(wrt==-1)
        {
           fprintf(stderr,"write(%s):%s \n",argv[1],strerror(errno));
           break;
        }
    }

    close(fd_src);
    close(fd_dst);
}