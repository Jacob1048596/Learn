namespace 字符串找第一个出现一次
{
    链接：https://www.nowcoder.com/questionTerminal/e896d0f82f1246a3aa7b232ce38029d4
来源：牛客网
/*思路：每出现一次，就在对应数组中计数+1*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        int a[128]={0};//保存出现次数
        bool flag=false;//判断是否找到
        for(int i=0;i<str.size();++i)
            ++a[str[i]];
        for(int i=0;i<str.size();++i)
        if(a[str[i]]==1)//判断是否是第一个只出现一次的字符
        {
             cout<<str[i]<<endl;
             flag=true;
             break;//注意要break;
        }
        if(flag==false)//如果没有找到
            cout<<"-1"<<endl;
    }
    return 0;
}
} // namespace 字符串找第一个出现一次

namespace 小易升级
{
    链接：https://www.nowcoder.com/questionTerminal/fe6c73cb899c4fe1bdd773f8d3b42c3d
来源：牛客网

#include <stdio.h>
int gcd (int m,int n){
    if (n == 0)
        return m;
    else
        return gcd(n,m%n);
}
int main() {
    int n,a,num;
    while(~scanf("%d %d",&n,&a)){
        for (int i=0;i<n;i++){
            scanf("%d",&num);
            if (num <= a)
                a+=num;
            else
                a+=gcd(num,a);
        }
        printf("%d\n",a);
    }
    return 0;
}
} // namespace 小易升级

