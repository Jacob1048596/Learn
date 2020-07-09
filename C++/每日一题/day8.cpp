#include<iostream>
using namespace std;
class cla{
    static int n;
    public:
    cla(){n++;}
    ~cla(){n--;}
    static int get_n(){return n;} 
};
class AB{
    int data;
    public:
    AB(int n=0)
    {
        data=n;
        cout<<"AB"<<endl;
    }
    ~AB(){cout<<"~AB"<<endl;}
};
int cla::n=0;
class A
{
    public:
    A():val(0){test();}
    virtual void func(){cout<<val<<' ';}
    void test(){func();}
    public:
    int val;
};
class B:public A
{
    public:
    B(){test();}
    virtual void func()
    {
        ++val;
        cout<<val<<' ';
    }
};
int main()
{
    
    int a,b;
    cin>>a;
    cin>>b;
    for(int i=0;i<=(a*b);i++)
    {
        if(((i%a)==0)&&((i%b)==0))
        {
            cout<<i<<endl;
            break;
        }
    }
        return 0;
}
int test()
{
    int a,b;
    cin>>a;
    cin>>b;
    for(int i=(a>b?a:b);i<=(a*b);i++)
    {
        if(((i%a)==0)&&((i%b)==0))
        {
            cout<<i<<endl;
            break;
        }
        
    }
}
/*
字典序排序，字符串大小排序
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>vec;

 //按照字典序排序
bool  lexicographically(){

    int i=0;
    string s;

    while((i+1) < vec.size()){
        if(vec[i].compare(vec[i+1]) >0)
            return 0;
        i++;
    }
    return 1;
}

//按照字符串大小排序
bool Lenths(){

    int i=0;
    while((i+1) <vec.size() ){
        if(vec[i+1].size() < vec[i].size() )
            return 0;
        i++;
    }
    return 1;
}

int main(){

    string s;
    int n,i=0;
    bool b1,b2;

    cin>>n;
    while(i < n){
        cin>>s;
        vec.push_back(s);
        i++;
    }

    b1=lexicographically();
    b2=Lenths();

    if(b1 && b2)
        cout<<"both";
    else if(b1 && !b2)
        cout<<"lexicographically";
    else if(!b1 && b2)
        cout<<"lengths";
    else
        cout<<"none";


    return 0;
}