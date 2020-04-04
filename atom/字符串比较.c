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
int main(int argc, char const *argv[]) {
  char* a="hh";
  char* b="hh";
  int p=mystrcmp(a,b);
  printf("%d\n",p);
  printf(a);
  return 0;
}
