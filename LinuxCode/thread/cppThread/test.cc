#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
using namespace std;
mutex m;
int sum=0;
atomic_int sum2{0};
void thread1(int a)
{
    
    for(int i=0;i<a;i++)
    {
        sum2++;
        //m.lock();
        sum++;
      // m.unlock();
    }
    
}

int main()
{
    thread t1(thread1,1000000);
    thread t2(thread1,1000000);
    thread t3(thread1,1000000);
    t1.join();
    t2.join();
    t3.join();
    t1.~thread();
    cout<<t1.get_id()<<endl;
    cout<<t2.get_id()<<endl;
    cout<<t3.get_id()<<endl;
   // pthread_exit(NULL);
    cout<<"sum="<<sum<<endl;
    cout<<"sum2="<<sum2<<endl;
    //t1.detach();
}