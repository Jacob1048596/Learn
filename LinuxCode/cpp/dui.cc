#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector<int> c;

template<class T,class Container>
class PriorityQueue
{
    public:
    void shiftup(int child)
    {
        while(child>0)
        {
        int parent=(child-1)/2;
        if(_c[parent]<_c[child])
        {
            swap(_c[parent],_c[child]);
            child=parent;
            parent=(child-1)/2;
        }
        else 
            break;
        }
    }
    void shiftdown(int parent)
    {
        while(parent<0)
        {
            int rchild=parent*2+1;
            int lchild=parent*2;
            if(parent*2+1>pq.size()) break;
            int maxchild=_c[rchild]>_c[lchild]?rchild:lchild;
            //if(_c[rchild]>_c[lchild]&&)
            if(_c[maxchild]>_c[parent])
            {
               swap(_c[parent],_c[maxchild]);
               parent=maxchild;
               rchild=parent*2+1;
               lchild=parent*2;
               maxchild= _c[rchild]>_c[lchild]?rchild:lchild;
               //parent*2+1
               
            }
            else break;



        }
    }
    void push(const T& val)
    {
        _c.push_back(val);
        shiftup(_c.size()-1);
    }
    void val()
    {
        return  _c.data();
    }
    int size()
    {
        return _c.size()
    }
    void 
    private:
    Container _c;
    
};

void test()
{
    PriorityQueue<int,vector<int>> pq;
    pq.push(10);
    pq.push(1);
    pq.push(6);
    pq.push(20);
    pq.push(4);
    for(int i=0;i<pq.size();i++)
    {
        cout<<pq.val()<<endl;
    }
}
int main()
{
    
    test();
    return 0;
}