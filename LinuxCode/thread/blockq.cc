#include<iostream>
#include<queue>
#include<thread>
using namespace std;
class BlockQueue
{
    private:
    queue<int> _queue;
    pthread_cond_t _cond_pro;
    pthread_cond_t _cond_cus;
    pthread_mutex_t _mutex;
    public:
    BlockQueue(){}
    int Pop(int *data){}//线程安全的出队接口
    int Push(const int data){}//线程安全的入队接口
    ~BlockQueue(){}

}；