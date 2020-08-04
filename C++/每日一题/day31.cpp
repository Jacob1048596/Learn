// write your code here cpp
#include<iostream>
#include<math.h>
using namespace std;
  void fun(int n)
 {
    cout<<n<<" =";
        int i;
        for(i=2;i<=sqrt(n);i++)
        {
            while(n!=i)
            {
                if(n%i==0)
                {
                    cout<<" "<<i<<" *";
                    n /= i;
                }
                else
                    break;              //否则就陷入死循环了
            }
        }
        cout<<" "<<n<<endl;
  }
int main()
{
    int a;
    while(cin>>a)
    {
        fun(a);
    }
}