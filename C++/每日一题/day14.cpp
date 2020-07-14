#include<iostream>
#include<string.h>
using namespace std;
int test1()
{
    char str1[]="is page fault";
    char str2[]="no page fault";
    strcpy(str1,"no");
    if(strcmp(str1,str2)==0)
    cout<<str2;
    else cout<<str1;
    
}
int test2()
{
    char str[]="gald to test something";
    char *p=str;
    p++;
    int * p1=reinterpret_cast<int*>(p);
    p1++;
    p=reinterpret_cast<char*>(p1);
    cout<<"result is "<<p<<endl;
}
int test3(unsigned int n)
{
    n=(n&0x55555555)+((n>>1)&0x55555555);
    n=(n&0x33333333)+((n>>2)&0x33333333);
    n=(n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);
    n=(n&0x00ff00ff)+((n>>8)&0x00ff00ff);
    n=(n&0x0000ffff)+((n>>16)&0x0000ffff);
    return n;
}
class base
{
    public:
    
}
int main()
{
    cout<<test3(197)<<endl;
}