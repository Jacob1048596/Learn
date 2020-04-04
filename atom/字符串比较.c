#include<stdio.h>
#include <string.h>
int mystrcmp(char* a,char* b)
{
  while (*a!='\0'||*b!='\0') {
    /* code */
    if(*a>*b) return 1;
    else if(*a<*b) return -1;
    else {a++;b++;}
  }
  return 0;
}
void test()
{
  char* arry[5]=
  {
    "hello",
  "TheWorld",
  "wryyyyyyy",
  "KonoDioDa!",
  "RoadRoller"
  };
  printf("%s\n",*arry);
  printf("%s\n",arry[0]);
  printf("%c\n",arry[0][1]);
  printf("%s\n",*arry);
  printf("%s\n",*arry+0);
  //printf("%c\n",**arry);
  printf("%s\n",*(arry+1));

}
int main(int argc, char const *argv[]) {
  // char* a="hh";
  // char* b="hh";
  // int p=mystrcmp(a,b);
  // printf("%d\n",p);
  // printf(a);
  test();
  return 0;
}
