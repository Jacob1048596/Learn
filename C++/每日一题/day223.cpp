#include<iostream>
using namespace std;
struct Date
{
    char a;
    int b;
    int64_t c;
    char d;
};
int main()
{
    Date a;
    cout<<sizeof(a)*15<<endl;
}