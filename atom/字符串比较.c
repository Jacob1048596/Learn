#include<stdio.h>
#include <string.h>
int mystrcmp(char* a,char* b)
{
  while (a||b) {
    /* code */
    if(*a>*b) return 1;
    else if(*a<*b) return -1;
    else {a++;b++;}
  }
}
int main(int argc, char const *argv[]) {
  char* a="hello";
  char* b="world";
  int p=mystrcmp(a,b);
  printf("%d\n",p);
  return 0;
}
