#include<iostream>
using namespace std;
bool fun(int n)
{
    int sum=0;
    for(int i=1;n<sum;i+=2)
    {
        sum+=i;
    }
    return (n==sum);
}
void test()
{
    cout<<fun(484);
}
int main()
{
    test();
}
namespace 汽水瓶
{
    #include<stdio.h>
 
int main (){
 
    int m;
 
    while(~scanf("%d",&m)&&m!=0) printf("%d\n",m/2);
 
    return 0;
 
}

#include <iostream>
  
using namespace std;
  
int f(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    return f(n-2)+1;
}
  
int main()
{
    int n;
    while(cin >> n){
        if(n==0)
            break;
        cout<<f(n)<<endl;
    }
    return 0;
}
} // namespace 汽水瓶


namespace 最长子串
{
    链接：https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
来源：牛客网

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        if (a.size() > b.size())
            swap(a, b);
        string str_m;//存储最长公共子串
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i; j < a.size(); j++)
            {
                string temp = a.substr(i, j - i + 1);
                    if (int(b.find(temp))<0)
                    break;
                else if (str_m.size() < temp.size())
                    str_m = temp;
            }
        }
        cout << str_m << endl;
    }
    return 0;
}
} // namespace 最长子串

