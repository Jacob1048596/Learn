#include<iostream>
using namespace std;
class myclass
{
    public:
    myclass(int i=0){cout<<1;}
    myclass(const myclass& x){cout<<2;}
    myclass& operator=(const myclass& x){cout<<3;return *this;}
    ~myclass(){cout<<4;}
};
int func(int n)
{
    n^=(1<<5)-1;
    return n;
}
class test
{
    public:
    int a;int b;
    virtual void fun(){}
    test(int temp1=0,int temp2 =0)
    {
        a=temp1;
        b=temp2;
    }
    int geta(){return a;}
    int getb(){return b;}
};
int main()
{
   test obj(5,10);
   int* pint=(int*)&obj;
   *(pint+0)=100;
   *(pint+1)=200;
   cout<<"a="<<obj.geta()<<endl;
     cout<<"b="<<obj.getb()<<endl;
     return 0;
}

int order(int n)
{
    if(n==1)
        return 1;
    return n*order(n-1);
}
int C(int m,int n)
{
    return order(m)/(order(n)*order(m-n));
}
int test1()
{
    int a,b;
   while( cin>>a>>b)
   {cout<<C(a+b,a)<<endl;}
}