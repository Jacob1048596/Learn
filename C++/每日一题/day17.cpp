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
    
}
void test3()
{
    char* ptr ;
    char str[]="abcdefg";
    ptr=str;
    ptr+=5;
    cout<<*ptr;
}
class A
{
    public:
    ~A(){cout<<"~A";}
};
class B
{
    public:
    virtual ~B(){cout<<"~B";}
};
class C:public A,public B
{
     public:
    ~C(){cout<<"~C";}
};
void test4()
{
    C* c=new C;
    B* b1=dynamic_cast<B*>(c);
    A* a2=dynamic_cast<A*>(b1);
    delete a2;
}
void test5()
{
    #include<iostream>
#include<string>
using namespace std;
int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        int temp = 0, carry = 0;
        while (a.size()<b.size())
            a = "0" + a;
        while (a.size()>b.size())
            b = "0" + b;
        for (int i = a.size() - 1; i >= 0; i--)
        {
 
            temp = a[i] - '0' + b[i] - '0' + carry;
            a[i] = temp%10 + '0';
            if (temp / 10)
                carry = 1;
            else
                carry = 0;
        }
        if (carry)
            a = "1" + a;
        cout << a << endl;
    }
    return 0;
}
}
int main()
{
    //test1();
    //test2();
    //test3();
    test4();
    
}