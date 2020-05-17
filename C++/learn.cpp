#include<iostream>
#include<stdio.h>
namespace N
{
    int test=233;
   long long int beast=1145141919810;
   void print(int a)
   {
       printf("%d \n",a);
   }
   
}
using namespace std;
int add(int a,int b)
{
    return a+b;
}
float add(float a,float b)
{
    return a+b;
}
int main()
{
    cout<<"C++ language"<<"?"<<endl;
    printf("C language\n");
    N::print(114514);
    N::print(N::test);
    cout<<N::beast<<endl; 
   //printf("%s",*N::beast);
    return 0;
}
