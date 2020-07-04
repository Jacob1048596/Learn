// #include<iostream>
// using namespace std;
// class A
// {
//     public:
//     A (char*s)
//     {
//         cout<<s<<endl;
//     }
//     ~A(){}
// };
// class B:virtual public A
// {
//     public:
//     B (char* s1,char* s2):A(s1)
//     {
//         cout<<s2<<endl;
//     }
// };
// class C:virtual public A
// {
//     public:
//     C (char* s1,char* s2):A(s1)
//     {
//         cout<<s2<<endl;
//     }
// };
// class D:public B,public C
// {
//     public:
//     D(char*s1,char*s2,char*s3,char*s4):B(s1,s2),C(s1,s3),A(s1)
//     {
//         cout<<s4<<endl;
//     }
// };
// int cunt=0;
// int fun(int n)
// {
//     cunt++;
//     if(n==0)
//         return 1;
//     else if(n==1)
//     {
//         return 2;
//     }else return fun(n-1)+fun(n-2);
// }
// int main()
// {
//   int a[5]={1,3,5,7,9};
//   int *p=(int*)(&a+1)
// }
// #include<iostream>
// using namespace std;
// int main()
// {
//  int a, b, c, d;
//     int A, B, C;
//     while(cin>>a>>b>>c>>d)
//     {
//         A=(a+c)/2;
//         B=(b+d)/2;
//         C=(d-b)/2;
//         if(A-B==a && B-C==b && A+B==c && B+C==d)
//         {
//             cout<<A<<" "<<B<<" "<<C<<endl;
//         }
//         else
//         {
//             cout<<"No"<<endl;
//         }
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
int main(){
    string s="",table="0123456789ABCDEF";
    int m,n;
    cin>>m>>n;
    if(m==0) cout<<0;
    while(m){
        if(m<0){
            m=-m;
            cout<<"-";
        }
        s=table[m%n]+s;
        m/=n;
    }
    cout<<s<<endl;
    return 0;
}