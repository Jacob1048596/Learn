#include<iostream>
using namespace std;
struct a
{
    /* data */
    void foo(){cout<<"foo";}
    virtual void bar(){cout<<"bar";}
    a(){bar();}
};
struct b:a
{
    /* data */
    void foo(){cout<<"b_foo";}
    void bar(){cout<<"b_bar";}
};
class printer
{
    public:
    printer(string name){cout<<name;}
};
class test
{
    public:
    test():b("b"),a("a"){}
    printer a;
    printer b;

};
int fun(int n)
{
    if(n==5)
    return 2;
    else
    {
        return 2*fun(n+1);
    }
    
}
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        int col,row;
        for(int i=0;i<3;i++)
        {
            if((board[i][0]==1)&&
               (board[i][1]==1)&&
               (board[i][2]==1))
                return true;
        }
        for(int j=0;j<3;j++)
        {
            if((board[0][j]==1)&&
               (board[1][j]==1)&&
               (board[2][j]==1))
                return true;
        }
          if((board[0][0]==1)&&
             (board[1][1]==1)&&
             (board[2][2]==1))
                return true;
        else if((board[0][2]==1)&&
               (board[1][1]==1)&&
               (board[2][0]==1))
                return true;
        else return false;
    }
};
int main()
{
    // int x=9999;
    // int count=0;
    // while(x)
    // {
    //     count++;
    //     x=x&(x-1);
    // }
    // cout<<count;

    cout<<fun(2);
    return 0;
}

void output(int& score)
{
    if(score>=90)
    {
        cout<<"VERY_SECURE";
    }else if(score>=80)
    switch (score)
    {
    case (score>=90):
         cout<<"VERY_SECURE";
        break;
    case ((score>=80)&&(score<90)):
        cout<<"SECURE";
        break;
    case ((score>=70)&&(score<80)):
         cout<<"VERY_STRONG";
        break;
    case ((score>=60)&&(score<70)):
         cout<<"STRONG";
        break;
    case ((score>=50)&&(score<60)):
         cout<<"AVERAGE";
        break;
    case ((score>=25)&&(score<50)):
         cout<<"WEAK";
        break;
    case ((score>=0)&&(score<25)):
         cout<<"VERY_WEAK";
        break;
    default:
        break;
    }
}

#include<iostream>
#include<string>
using namespace std;
int lenScore(string& passwd)
{
    int len=passwd.length();
    if(len<=4) return 5;
    else if(len>=5&&len<=7) return 10;
    else if(len>=8) return 25;
}
int abcScore(string& passwd)
{
    int flag=0;
    int bigflag=0;
    string::iterator it=passwd.begin();
    while(it!=passwd.end())
    {
        if((*it>'a')&&(*it<'z'))
        {
            it++;
            flag=1;
            continue;
           
        }else if((*it>'A')&&(*it<'Z'))
        {
            it++;
           bigflag=1;
           continue;
        }
        else it++;
    }
    if((flag+bigflag)==0) return 0;
    else if((flag+bigflag)==1) return 10;
    else if((flag+bigflag)==2) return 20;
}
int numScore(string& passwd)
{
     string::iterator it=passwd.begin();
    int numcount=0;
    while(it!=passwd.end())
    {
        if((*it>='0')&&(*it<='9'))
        {
            numcount++;
            it++;
            continue;
        }
        it++;
    }
    if(numcount==0) return 0;
    else if(numcount==1) return 10;
    else if(numcount>1) return 20;
}
int signScore(string& passwd)
{
    string::iterator it=passwd.begin();
    int signc=0;
    while(it!=passwd.end())
    {
        if(
            ((*it>=0x21)&&(*it<=0x2f))||
            ((*it>=0x3a)&&(*it<=0x40))||
            ((*it>=0x5b)&&(*it<=0x60))||
            ((*it>=0x7b)&&(*it<=0x7e))
          )
        {
            it++;
            signc++;
            continue;
        }
        it++;
    }
     if(signc==0) return 0;
    else if(signc==1) return 10;
    else if(signc>1) return 25;
}

void output(int& score)
{
    if(score>=90)
    {
        cout<<"VERY_SECURE";
    }else if((score>=80)&&(score<90))
        cout<<"SECURE";
    else if((score>=70)&&(score<80))
        cout<<"VERY_STRONG";
    else if((score>=60)&&(score<70))
        cout<<"STRONG";
    else if((score>=50)&&(score<60))
        cout<<"AVERAGE";
    else if((score>=25)&&(score<50))
         cout<<"WEAK";
    else if((score>=0)&&(score<25))
        cout<<"VERY_WEAK";
}
int main()
{
    string password;
    cin>>password;
    int len=lenScore(password);
    int abc=abcScore(password);
    int num=numScore(password);
    int sign=signScore(password);
    int tempscore=len+abc+num+sign;
    if(((abc+num)>10)&&(abc==10))
        tempscore+=2;
    if((abc==10)&&(num>0)&&(sign>0))
        tempscore +=3;
    if((abc==20)&&(num>0)&&(sign>0))
        tempscore +=5;
    int score=tempscore;
    output(score);
}