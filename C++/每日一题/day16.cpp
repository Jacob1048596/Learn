#include<iostream>
using namespace std;
void test1()
{
    const int a=10;
    int *p=(int*)(&a);
    *p=20;
    cout<<"A="<<a<<endl;
    cout<<"*P="<<*p<<endl;
}
class base
{
    public:
    virtual int foo(int x) {return x*10;}
    int foo(char x[14]){return sizeof(x)+10;}
};
class derived:public base
{
    public:
    int foo(int x){return x*20;}
    virtual int foo(char x[10]){return sizeof(x)+20;}
};
void test2()
{
    derived str;
    base* pstbase=&str;
    char x[10];
    cout<<pstbase->foo(100)+pstbase->foo(x)<<endl;
}
void test3()
{
   int i=3;
   cout<<++i<<++i<<endl;

}
struct test
{
    /* data */
    test(int){}
    test(){}
    void fun(){}
};
class widget
{
    public:
    widget(int data=0){cout<<"widget"<<endl;}
    widget(const widget& w){data=w.data;cout<<"copy widget"<<endl;}
    private:
    int data;
};
widget f(widget u)
{
    widget v(u);
    widget w=v;
    return w;
}
void swap_int(int * a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
int main()
{
    int a=10,b=20;
    swap_int(&a,&b);
    cout<<a<<endl<<b<<endl;
}
void poker()
{
    #include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> split(string str,char sep){
    stringstream ss(str);
    string temp;
    vector<string> res;
    while(getline(ss,temp,sep)){
        res.push_back(temp);
    }
    return res;
}
int judgePoker(vector<string> poker){
    int flag=-1;
    if(poker.size()==1){
            flag=0;//个子
    }
    else if(poker.size()==2){
        if(poker[0]==string("joker")||poker[1]==string("joker"))
            flag=5;//对王
        else
            flag=1;//普通对子
    }
    else if(poker.size()==3)
        flag=2;//三个
    else if(poker.size()==4)
        flag=3;//炸弹
    else if(poker.size()==5)
        flag=4;//顺子
    return flag;
}
 
int main(){
    string str;
    vector<string> table={"3","4","5","6","7","8","9","10",
                          "J","Q","K","A","2","joker","JOKER"};
    while(getline(cin,str)){
        int win=-1;//0表示不能比，1表示第一幅，2表示第二幅
        vector<string> vec=split(str,'-');
        vector<string> poker1=split(vec[0],' ');
        vector<string> poker2=split(vec[1],' ');
        int flag1=-1,flag2=-1;
        flag1=judgePoker(poker1);
        flag2=judgePoker(poker2);
        if(flag1==5||flag2==5||flag1==3||flag2==3){
            if(flag1==5)//一方有对王
                win=1;
            else if(flag2==5)
                win=2;
            else if(flag1==flag2&&flag1==3){//都是炸弹
                auto it1=find(table.begin(),table.end(),poker1[0]);
                auto it2=find(table.begin(),table.end(),poker2[0]);
                if(it1<it2)
                    win=2;
                else
                    win=1;
            }
            else if(flag1==3&&flag2!=3)//只有一方有炸弹
                win=1;
            else if(flag1!=3&&flag2==3)
                win=2;
        }
        else if(flag1==flag2){
            auto it1=find(table.begin(),table.end(),poker1[0]);
            auto it2=find(table.begin(),table.end(),poker2[0]);
            if(it1<it2)
                win=2;
            else
                win=1;
        }
        else
            win=0;
        if(!win)
            cout<<"ERROR"<<endl;
        else if(win==1){
            int i=0;
            for(;i<poker1.size()-1;i++)
                cout<<poker1[i]<<" ";
            cout<<poker1[i]<<endl;
        }
        else if(win==2){
            int i=0;
            for(;i<poker2.size()-1;i++)
                cout<<poker2[i]<<" ";
            cout<<poker2[i]<<endl;
        }
    }
    return 0;
}
}
void perfectNumber()
{
    #include <iostream>
#include <algorithm>
using namespace std;
int Count(int n){
    int count = 0;
    if(n < 0 || n > 500000){
        return -1;
    }
    for(int i = 2; i <= n; ++i){
        int sum = 0;
        for(int j = 2; j <= sqrt(i); ++j){
            if(i % j == 0){
                //如果j^2 = i，说明两个约数相同，只加一个
                if(i / j == j){
                    sum += j;
                }
                else{
                    //否则，两个不同的约数都要相加
                    sum += j + (i / j);
                }
            }
        }
        if(sum + 1 == i){
        ++count;
        }
    }
    return count;
}
int main(){
    int n;
    while(cin >> n){
        cout << Count(n) << endl;
    }
    return 0;
}
}