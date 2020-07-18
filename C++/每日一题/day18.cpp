#include<iostream>
using namespace std;
int f(int n)
{
    static int i=1;
    if(n>=5)
    return n;
    n+=i;
    i++;
    return f(n);
}
class A
{
    public:
    void print(){cout<<"AP"<<endl;}
};
class B:private  A
{
    public:
     void print(){cout<<"BP"<<endl;}
};
class C:public B
{
    public:
     void print(){A::print();}
}
void test()
{
    //cout<<f(1)<<endl;

    C b;
    b.print();
}
int main()
{
    test();
}
namespace rabbit
{
    #include<iostream>
using namespace std;
int getnum(int n)
{
    if(n<0) return 0;
    if((n==1)||(n==2)) return 1;
    int x1=1;
    int x2=1;
    int x3;
    for(int i=3;i<n+1;i++)
    {
        x3=x2+x1;
        x1=x2;
        x2=x3;
    }
    return x3;
}
int main()
{
    int month;
    while(cin>>month)
    {
        cout<<getnum(month)<<endl;
    }
}
} // namespace rabbit;
namespace 通配符
{
//     链接：https://www.nowcoder.com/questionTerminal/43072d50a6eb44d2a6c816a283b02036
// 来源：牛客网

// 用递归就可以了
#include <iostream>
#include <string>
using namespace std;
 
bool match(const char* pattern, const char *str)
{
    if (*pattern == '\0' && *str == '\0')
        return true;
    if (*pattern == '\0' || *str == '\0')
        return false;
 
    if (*pattern == '?')
    {
        return match(pattern + 1, str + 1);
    }
    else if (*pattern == '*')
    {
        // 匹配0个1个或多个
        return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
    }
    else if (*pattern == *str)
    {
        return match(pattern + 1, str + 1);
    }
 
    return false;
}
int main(void)
{
    string pattern, str;
    while (cin >> pattern >> str)
    {
        bool ret = match(pattern.c_str(), str.c_str());
        if (ret)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}

}