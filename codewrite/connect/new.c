#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
    int fds[2];
    pipe(fds)
    /

    if(fork()==0)
    {
        close(fds[0]);
        sleep(2);
        write(fds[1],"test",4);
        close(fds[1]);
        
    }else{
        close(fds[1]);
        char buf[10];
        read(fds[0],buf,10);
        printf("buf=[%s]\n",buf);
        close(fds[0]);
    }

    return 0;
}
