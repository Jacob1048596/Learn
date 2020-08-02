#include<iostream>
using namespace std;

int main()
{

}
// write your code here#
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
string passwd(string str)
{
    string ret(str);
    for(int i=0;i<str.length();i++)
    {
        if(str[i]<'A'&&str[i]>'Z') continue;
        if((str[i]>'A')&&(str[i]<'Z')&&((str[i]-5)>'A'))
        {
            ret[i]=str[i]-5;
        }
        else if((str[i]>'A')&&(str[i]<'Z')&&(str[i]-5)<'A')
        {
            ret[i]=(str[i]-4+'Z'-'A');
        }
    }
    //ret[str.length()]='\0';
    return ret;
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        cout<<passwd(str)<<endl;
    }
}
namespace 最难的问题
{
    #include <stdio.h>
 
int main() {
    int c;
    while ((c = getchar()) != EOF){
        if ('A' <= c) {
        c = 'E' < c ? (c - 5) : (c + 21);
        }
        putchar(c);
    }
}//运算优于查表，查表优于判断，哭了
} // namespace 最难的问题
namespace 因子个数
{
    #include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int sum=0;
        for(int i=2;i<sqrt(n);i++)
        {
            int d=0;
            while(n%i==0)
            {
                d=1;
                n=n/i; 
            }

            if(d) sum++;
            if(n==1) break;
        }
        if(n!=1) sum++;
        cout<<sum<<endl;
    }
 } 
} // namespace 因子个数
