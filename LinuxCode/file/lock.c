#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd=open("test.txt",O_RDWR|O_TRUNC);
    struct flock lock;
    memset(&lock,0x00,sizeof(lock));
    lock.l_type=F_WRLCK;//write
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;

   if( fcntl(fd,F_SETLKW,&lock)==-1)
    perror("Fcntrl"),exit(1);
    else
    {
        printf("lock ok\n");
    }
    printf("input return to unlock\n");
    while (getchar()=='\n')
    {
        ;
    }
    //unlock
    lock.l_type=F_UNLCK;
    if(fcntl(fd,F_SETLKW,&lock)==-1)
    perror("Fcntrl"),exit(1);
    else
    printf("unlock ok");
    

}