#include<queue>
#include<thread>
using namespace std;
class ThreadPool
{
    public:
    ThreadPool(){
        pthread_mutex_init(&_mutex,NULL);
        pthread_cond_init(&_cond_pro,NULL);
        pthread_cond_init(&_cond_cus,NULL);
    };
    ~ThreadPool(){
        pthread_mutex_destroy(&_mutex,NULL);
        pthread_cond_destroy(&_cond_pro,NULL);
        pthread_cond_destroy(&_cond_cus,NULL);
    }
    bool TaskPush(const ThreadTask &task)
    {
        return true;
    }
    void* thr_start(void*arg)
    {
        
    }
    private:
    int _thread_max;
    int _capicity;
    queue<ThreadTask> _queue;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond_pro;
    pthread_cond_t _cond_cus;

};