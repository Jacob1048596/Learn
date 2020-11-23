#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;


int main()
{
   string str;
   string ch;
   getline(cin,str);
   getline(cin,ch);
  for (int i = 0; i < ch.size(); i++)
    {
        int index;
        while((index=str.find(ch[i]))!=-1)
        {
            str.erase(index, 1);
        }
    }
   cout<<str<<endl;
}