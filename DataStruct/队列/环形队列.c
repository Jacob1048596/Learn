#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  /* code */
  printf("%d\n",(-1&7) );
  printf("%d\n",(0&7) );
  int x=10;
  printf("%d\n",~x );
  printf("%d\n",x^-1 );
  return 0;
}
