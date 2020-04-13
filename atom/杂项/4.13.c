#include <stdio.h>
#include <math.h>
double my_abs(double a)
{
  if(a>=0) return a;
  else return -1*a;
}
int main(int argc, char const *argv[]) {
  int num=1000000;
  double pie=0.0;
  double a=1;
  for( int i=1,j=0;my_abs(a)>0.00001;i=i+2,++j)
  {
       a=(pow(-1,j)/i);
      pie+=(pow(-1,j)/i);
  }
  printf("%.2f\n",pie*4);
  return 0;
}
