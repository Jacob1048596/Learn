#include<iostream>
using namespace std;
void test1()
{
    const int a=10;
    int *p=(int*)(&a);
    *p=20;
    cout<<"A="<<a<<endl;
    cout<<"*P="<<*p<<endl;
}
class base
{
    public:
    virtual int foo(int x) {return x*10;}
    int foo(char x[14]){return sizeof(x)+10;}
};
class derived:public base
{
    public:
    int foo(int x){return x*20;}
    virtual int foo(char x[10]){return sizeof(x)+20;}
};
void test2()
{
    derived str;
    base* pstbase=&str;
    char x[10];
    cout<<pstbase->foo(100)+pstbase->foo(x)<<endl;
}
void test3()
{
   int i=3;
   cout<<++i<<++i<<endl;

}
struct test
{
    /* data */
    test(int){}
    test(){}
    void fun(){}
};
class widget
{
    public:
    widget(int data=0){cout<<"widget"<<endl;}
    widget(const widget& w){data=w.data;cout<<"copy widget"<<endl;}
    private:
    int data;
};
widget f(widget u)
{
    widget v(u);
    widget w=v;
    return w;
}
void swap_int(int * a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
int main()
{
    int a=10,b=20;
    swap_int(&a,&b);
    cout<<a<<endl<<b<<endl;
}