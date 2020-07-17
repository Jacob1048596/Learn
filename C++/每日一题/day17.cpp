#include<iostream>
using namespace std;
class a
{
    public:
    a(){p();}
    virtual void p(){cout<<"A"<<endl;}
    virtual ~a(){p();}
};
class b:public a
{
    public:
    b(){p();}
    virtual void p(){cout<<"B"<<endl;}
    ~b(){p();}
};
template <class T>
struct sum
{
    /* data */
    static void foo(T op1,T op2){cout<<op1<<op2;}
};

void test1()
{
    // a* a=new b();
    // delete a;
    sum<int>::foo(1,3);
}
void test2()
{
    char* p="abc";
    char* q="abc123";
    while(*p=*q)
    cout<<*p<<*q;
    print
}
int main()
{
    //test1();
    test2();
    
}