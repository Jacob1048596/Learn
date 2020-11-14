#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<signal.h>
#include<sys/ioctl.h>
#include<termio.h>
#include<sys/time.h>
#define FC 5
#define BC 0
struct data
{
  int x;
  int y;
    /* data */
};
struct data t={.x=5,.y=5};
struct shape
{
    int s[5][5];
};
struct shape shape_arr[7]=
{
    {
    0,0,0,0,0,
    0,0,1,0,0,
    0,1,1,1,0,
    0,0,0,0,0,
    0,0,0,0,0,
    },
    {
    0,0,0,0,0,
    0,1,1,0,0,
    0,0,1,1,0,
    0,0,0,0,0,
    0,0,0,0,0,
    },
    {
    0,0,0,0,0,
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,1,1,0,
    0,0,0,0,0,
    },
    {
    0,0,0,0,0,
    0,0,1,0,0,
    0,0,1,0,0,
    0,1,1,0,0,
    0,0,0,0,0,
    },
    {
    0,0,0,0,0,
    0,1,1,0,0,
    0,1,1,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    },
    {
    0,0,0,0,0,
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,1,0,0,
    0,0,0,0,0,
    },
    {
     0,0,0,0,0,
     0,0,1,1,0,
     0,1,1,0,0,
     0,0,0,0,0,
     0,0,0,0,0,
    }
};
void drap_element(int x,int y,int c)
{
    x++;
    y++;
    x=x*2;
    printf("\033[%d;%dH\033[3%dm\033[4%dm[]\033[?25l\033[0m",y,x,c,c);
    fflush(stdout);
}
void drap_shape(int x,int y,struct shape p,int c)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(p.s[i][j]!=0)
            drap_element(x+j,y+i,c);
        }
    }
}

void tetris_timer(struct data *t)
{
    
    drap_shape(t->x,t->y,shape_arr[0],BC);
    t->y++;
    drap_shape(t->x,t->y,shape_arr[0],FC);
}
void handler(int s)
{
    tetris_timer(&t);
}
void handler_int(int s)
{
    printf("\033[?25h");
    exit(0);
}

void tetris(struct data *t)
{
    
}
int main()
{
    signal(SIGALRM,handler);
    signal(SIGINT,handler_int);
    struct itimerval it;
    it.it_value.tv_sec=0;
    it.it_value.tv_usec=1;
    it.it_interval.tv_sec=1;
    it.it_interval.tv_usec=0;
    setitimer(ITIMER_REAL,&it,NULL);

   for(;;)
   {

   }
    
}