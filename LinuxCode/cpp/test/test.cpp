#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<list>

using namespace std;
template<class T>
class Queue
{
   public:
    void push(const* T val)
    {
        lst.push_back(val);
    }
    void pop()
    {
        lst.pop_front();
    }
    T& front()
    {
        lst.front();
    }
    bool empty()
    {
        lst.empty();
    }
    T& back()
    {
        lst.back();
    }
    size_t size()
    {
        lst.size();
    }
    private:
    list<T> lst;
};

int evalRPN(vector<string>&tokens)
{
    stack<string> stk;
    // for(auto& str:tokens)
    // {
    //      if(str=='+'||*it=='-')
    //     {

    //     }
    //     stk.push(*it);
    // }
    vector<string>::iterator it=tokens.begin();
    // int i=0;
    // while(it!=tokens.end())
    // {
    //     if(tokens[0]=='+'||tokens[i]=='-'||tokens[i]=='*'||tokens[i]=='/')
    //     {

    //     }
    //     stk.push(*it);
    // }
    
}