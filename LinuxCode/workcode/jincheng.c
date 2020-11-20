#include<stdio.h>
#include<unistd.h>
int main()
{
    int data=3;
   for(int i=0;i<data;i++)
   {
       if(fork()==0)
       break;
   }
   getchar();
    // if(id==0)
    // {
    //     #if  1
    //     while(1) 
    //     {
    //         printf("++++++++child,pid=%d,ppid=%d\n",getpid(),getppid());
    //         sleep(1);
    //     }
    //     #endif
    // }
    // else {
    //     #if 1
    //     while (1)
    //     {
            
    //         /* code */printf("######parent,pid=%d\n",getpid());
    //         sleep(1);
            
    //     }
    //     #endif 
        
    // }
    //  switch (id)
    //  {
    //  case -1:
    //      /* code */
    //      printf("FORK ERROR\n");
    //      break;
    //  case 0:
    //     data=200;
    //     printf("CHILD: %p,&data:%p,data:%d\n",&main,&data,data);
    //     break;
    //  default:
    //     sleep(1);
    //     printf("parent: %p,data:%p,data:%d\n",&main,&data,data);
    //      break;
    //  }
}