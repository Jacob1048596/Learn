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
// int add(int a,int b)
// {
//     return a+b;
// }
// float add(float a,float b)
// {
//     return a+b;
// }
class test
{
private:
    /* data */
    int _a;
public:
  void SetData(int data)
  {
      _a=data;
  }
  void PrintData()
  {
      cout<<_a<<" "<<endl;
  }
    
};

int main()
{
    cout<<"C++ language"<<"?"<<endl;
    printf("C language\n");
    N::print(114514);
    N::print(N::test);
    cout<<N::beast<<endl; 
    test a;
    a.SetData(10);
    a.PrintData();
   //printf("%s",*N::beast);
   cout<<sizeof(test)<<endl;
   cout<<"测试"<<endl;
    return 0;
}
