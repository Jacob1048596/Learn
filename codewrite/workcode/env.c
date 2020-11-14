#include<stdio.h>
#include<stdlib.h>

int main(int argc, char*argv[], char* envp[])
{
    // int i;
    // printf("argc=%d\n",argc);
    // for(i=0;i<10;i++)
    // {
    //     printf("argv[%d]:%s\n",i,argv[i]);
    // } 
//    for(int i=0;envp[i]!=NULL;i++)
//     {
//         printf("envp[%d]:%s\n",i,envp[i]);
//     } 
    char *bash=getenv("SHELL");
    if(bash) printf("%s\n",bash);
    if(putenv("AAA=aaa")==0) printf("putenv success\n");
    else printf("putenv error\n");
    bash=getenv("AAA");
    if(bash) printf("%s\n",bash);
}