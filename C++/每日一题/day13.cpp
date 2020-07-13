#include<iostream>
using namespace std;
class b
{
    public:
    b(){cout<<"default constructor"<<endl;}
    ~b(){cout<<"destructed"<<endl;}
    b(int i):data(i){ cout<<"construct by paramter"<<endl;}
    private:int data;
};
b play(b B)
{
    return B;
}
class A
{
    public:
    virtual void print(){cout<<"A::print"<<endl;}
};
class B:public A
{
    public:
    virtual void print(){cout<<"B::print"<<endl;}
};
class C :public A
{
    public:
    virtual void print(){cout<<"C::print"<<endl;}
};
void print(A a)
{
    a.print();
}
int main()
{
  A a,*aa,*ab,*ac;
  B b;
  C c;
  aa=&a;
  ab=&b;
  ac=&c;
  a.print();
  b.print();
  c.print();
  aa->print();
  ab->print();
  ac->print();
  print(a);
  print(b);
  print(c);
}

链接：https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
来源：牛客网

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
#define INT_MAX 100001
int main()
{
    int n, m;
    while(cin >> n >> m)
      {
         vector<int> dp(m + 1, INT_MAX);  //dp[i]为在第i个石板时，所需要的步数，初始设为条件范围内的最大值
         dp[n] = 0;
         for (int i = n; i <= m; i++)
            {
             for (int j = 2; j*j <= i; j++)   //比如i为8，当找到i的一个约数j为2时，另一个约数就为i/j
                {                             //所以只需要找j*j<=i,事实上如果不这样做，部分用例运行超时
                 if (i%j == 0)
                    {
                      if (i + j <= m)
                         dp[i + j] = min(dp[i + j],dp[i]+1);
                      if(i+i/j<=m) //关键步骤
                         dp[i + i/j] = min(dp[i + i/j],dp[i]+1);
                    }
                }
           }
       if(dp[m]==INT_MAX)
           cout<<"-1"<<endl;
       else
           cout<<dp[m]<<endl;
     }
}