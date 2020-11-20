#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main()
{
 int fd=open("test.txt",O_RDONLY);
 if(fd==-1) perror("open"),exit(1);   
 printf("OPen OK\n");
 char buf[10];
 memset(buf,0x00,sizeof(buf));
 int r=read(fd,buf,10);
 if(r==-1) perror("read"),exit(1);
 printf("buf=[%s]\n",buf);

 if(close(fd)==-1) perror("close"),exit(1);
}