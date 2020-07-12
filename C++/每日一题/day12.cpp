#include<iostream>
using namespace std;
void fun(const int& v1,const int& v2)
{
    cout<<v1<<endl;
    cout<<v2;
}

class base
{
    public:
    int bar(char x) {return (int)(x);}
    virtual int bar(int x){ return (2*x);}
};
class derived:public base
{
    public:
    int bar(char x){return (int)(-x);}
    int bar(int x){return (x/2);}
};
int main()
{
    derived obj;
    base* pobj=&obj;
    cout<<pobj->bar((char)(100))<<endl;;
    cout<<pobj->bar(100);
}

#include <cmath>
#include <iostream>
using namespace std;
 
bool isPrime(int i)
{
    for (int j = 2; j <= sqrt(i * 1.0); j++) {
        if (i % j == 0)
            return false;
    }
    return true;
}
 
int test() {
    int n;
    int Prime1, Prime2;
    while (cin >> n) {
        if (n < 2)
            return 1;
        else {
            for (int i = 1; i <= n / 2;i++) {
                if (isPrime(i) && isPrime(n - i)) {
                    Prime1 = i;
                    Prime2 = n - i;
                }
            }
            cout << Prime1 << endl;
            cout << Prime2 << endl;
            }
    }
    return 0;
}
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // m左移j位
        m <<= j;
        return n | m;
    }
};