#include<stdio.h>
#include<unistd.h>

int main()
{
    char buf[100]={};
    int i;
    for(i=0;i<100;i++)
    {
        buf[i]='#';
        printf("[%-100s]%d%%\r",buf,i+1);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}