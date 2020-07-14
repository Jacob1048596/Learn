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
    base(int j):i(j){}
    virtual ~base(){}
    void fun1(){
        i*=10;
        fun2();
    }
    int getval(){return i;}
    protected:
    virtual void fun2(){i++;}
    protected: int i;
};
class child:public base
{
    public:
    child(int j):base(j){}
    void fun1()
    {
        i*=100;
        fun2();
    }
    protected:
    void fun2(){i+=2;}
};
// int main()
// {
//    base* pb=new child(1);
//    pb->fun1();
//    cout<<pb->getval()<<endl;
//    delete pb;
// }
//#include<iostream>
// using namespace std;
bool isrun(int year)
{
    if((year%400==0)||(year%4==0)&&(year%100!=0)) return true;
    else return false;
}
int mdate(int year,int month)
{
    if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)) return 31;
        else if((month==4)||(month==6)||(month==9)||(month==11)) return 30;
    if(month==2)
    {
        if(isrun(year)==true) return 29;
        else return 28;
    }
}
int date(int year,int month,int day)
{
    int date=0;
    for(int i=1;i<month;i++)
    {
        date+=mdate(year,i);
    }
    return date+day;
}
int year()
{
    int year,month,day;
   while( cin>>year>>month>>day)
   { cout<<date(year,month,day)<<endl;}
}
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int n,a[1007];
 
int DFS(int step, int sum, int mul)
{     
    int r = 0;     
    for(int i=step+1;i<n;i++)
    { 
        int S = sum+a[i];
        int M = mul*a[i];
        if(S > M)
            r += 1 + DFS(i,S,M);
        else if(a[i]==1)
            r += DFS(i,S,M);
        else
            break;
        while(i<n-1 && a[i]==a[i+1])i++;
    }     return r;
}
 
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<DFS(0,1,1)<<endl;
    return 0;
}]