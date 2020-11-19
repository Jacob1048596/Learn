#include "thread.h"
#include<unistd.h>
class test_thread: public Thread{
    public:
    test_thread(bool flag):Thread(flag){cout<<"test_thread()"<<endl;}
    ~test_thread(){cout<<"~test_thread()"<<endl;}
    private:
    void run()
    {
        int i;
        for(i=0;i<5;i++)
        {
            cout<<"i="<<i<<endl;
            sleep(1);
        }
    }
};
int main()
{
    Thread* t=new test_thread(true);
    t->start();
    t->join();
    //delete(t);
}