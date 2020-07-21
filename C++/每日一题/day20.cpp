#include<iostream>
using namespace std;
void test()
{
    iterator
}
int main()
{
    test();
}
namespace 公共子串
{
    #include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1,str2;
    int dis=0,t=0;
    string tmp;
    while(cin>>str1>>str2)
    {
        int len=str1.length();
        for(int i=len;i>1;i--)
        {
            for(int j=0;j<len;j++)
            {
                if(i+j<=len)
                {
                    tmp=str1.substr(j,i);
                    t=str2.find(tmp);
                    if(t!=-1&&tmp.length()>dis)
                        dis=tmp.length();
 
                }
            }
        }
        cout<<dis<<endl;
    }
 
    return 0;
}
} // namespace 公共子串
