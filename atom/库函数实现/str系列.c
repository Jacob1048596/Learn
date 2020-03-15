#include<stdio.h>
#include <assert.h>
#include <string.h>
int Strcmp(const char* str1,const char* str2)
{
   assert(str1!=NULL&&str2!=NULL);
   while (*str1!='0'&&*str2!='0')
  {
     if (*str1>*str2) { return 1; }
     else if (*str1<*str2) { return -1; }
     else  {str1++;str2++;}
   }
}
int Strlen(const char* str)
{
  assert(str!=NULL);
  int ret =0;
  while (*str!='\0') {
    /* code */
    ret++;
    str++;
  }
  return ret;
}
char* Strcpy(char* destination, const char* source)
{
   assert(destination!=NULL&&source!=NULL);
  char* ret=destination;
   if(strlen(destination)<strlen(source)) return NULL;
   while (*destination!='\0'&&*source!='\0') {
     /* code */
     *destination=*source;
     destination++;
     source++;
   }
   *destination='\0';
   return ret;
 }
char* Strcat(char* destination,const char* source)
{
   assert(destination!=NULL&&source!=NULL);
   char* ret=destination;
  if(strlen(destination)<strlen(source)) return NULL;
  while (*destination!='\0') {
    destination++;
  }
  while (*source!='\0') {
    *destination=*source;
    destination++;
    source++;
  }
  *destination='\0';
  return ret;

 }
const char* Strstr(const char* destination,const char* source)
 {
   assert(destination!=NULL&&source!=NULL);
   const char* black=destination;
   while (*black!='\0')
   {
     const char* red=black;
     const char* sub =source;
     while ((*red!='\0')&&(*sub!='\0')&&(*sub==*red))
     {
         red++;
         sub++;
     }
     if(*sub=='\0') return black;
     if(*red=='\0') return NULL;
     black++;
   }
  return NULL;
 }
 char* Strtok(char* str,const char* sep)//Î´Íê³É
 {
  char* cut=str;
   while (str!=sep) {
     str++;
   }
   *str='\0';
   return cut;
 }
int main(int argc, char const *argv[]) {
  /* code */
  char str1[100]="hello WorldwwwwwwwWORLDWorld!";
  char* str=NULL;
  int lenth=Strlen(str1);
  //printf("%d\n",lenth);
  //const char* p=Strstr(str1,"WORLD");
  char* result=Strtok(str1," ");
  printf("%s\n",result);


  return 0;
}
