#include<iostream>
using namespace std;
// class a
// {
//     public:
//     a(){cout<<"a"<<endl;}
//     ~a(){}
//     virtual void func(int val=1)
//     {
//         cout<<"A->"<<val<<endl;
//     }
//     virtual void test(){func();}
// };
// class b:public a
// {
//     public:
//     void func(int val=0)
//     {
//         cout<<"A->"<<val<<endl;
//     }
// };
// #define N 9
// int x[N];
// int count=0;
// void dump()
// {
//     for(int i=0;i<N;i++)
//     {
//         cout<<x[i];
//     }
//     cout<<endl;
// }
// void swap(int a,int b)
// {
//     int t=x[a];
//     x[a]=x[b];
//     x[b]=t;
// }
// void run(int n)
// {
    
//     if(N-1==n)
//     {
//         dump();
//         count++;
//         return;
//     }
//     for(int i=n+1;i<N;i++)
//     {
//         swap(n+1,i);
//         run(n+1);
//         swap(n+1,i);

//     }
// }
int fun(int n)
{
    if(n<2) return n;
    else return 2*fun(n-1)+fun(n-2);
}
int main()
{
 cout<<fun(5);
}
class LCA {
public:
    int getLCA(int a, int b) {
       while(a!=b)
       {
            while(a>b) a/=2;
            while(a<b) b/=2;
        }
        return a;
    }
};
#include<iostream>
using namespace std;
int main()
{
    int byte;
    while(cin>>byte)
    {
        int k=0;
        for( k=0;byte!=0;k++)
        {
            byte=byte&(byte<<1);
        }
        cout<<k<<endl;
    }
    return 0;
}