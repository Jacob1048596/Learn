#include<iostream>
#include<stdio.h>
namespace N
{
    int test=233;
   long long int beast=1145141919810;
   void print(int a)
   {
       printf("%d \n",a);
   }
   
}
using namespace std;
// int add(int a,int b)
// {
//     return a+b;
// }
// float add(float a,float b)
// {
//     return a+b;
// }
class test
{
private:
    /* data */
    int _a;
public:
  void SetData(int data)
  {
      _a=data;
  }
  void PrintData()
  {
      cout<<_a<<" "<<endl;
  }
    
};

class Date
{
private:
    int _year;
    int _month;
    int _date;
public:
    Date(int y,int m,int d);
    ~Date();
    Date DateCopy(Date& d)
    {
        _year=d._year;
        _month=d._month;
        _date=d._date;
    }
    void PrintD()
    {
        cout<<_year<<" "<<_month<<" "<<_date<<endl;
    }
//     ostream& operator<<(ostream& _cout,const Date& d)
// {
//     _cout<<d._year<<" "<<d._month<<" "<<d._date<<endl;
// }
    Date operator+(int day)
    {
        _date+=day;
        return *this;
    }
};

Date::Date(int y=1,int m=1,int d=1)
{
    _year=y;
    _month=m;
    _date=d;
}
// ostream& operator<<(ostream& _cout,const Date& d)
// {
//     _cout<<d._year<<" "<<d._month<<" "<<d._date<<endl;
// }
Date::~Date()
{
    cout<<"~Date()"<<endl;
}

int main()
{
//     cout<<"C++ language"<<"?"<<endl;
//     printf("C language\n");
//     N::print(114514);
//     N::print(N::test);
//     cout<<N::beast<<endl; 
//     test a;
//     a.SetData(10);
//     a.PrintData();
//    //printf("%s",*N::beast);
//    cout<<sizeof(test)<<endl;
//    cout<<"测试"<<endl;
    Date D1(2000,12,25);
    D1.PrintD();
    Date D2=D1+5;
    D2.PrintD();
    return 0;
}
