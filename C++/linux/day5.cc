#include<iostream>
#include<string>

using namespace std;
bool istrue(string &str)
{
    string::iterator start=str.begin();
    string::iterator end=--str.end();
    bool flag=false;
    while(start!=end)
    {
        if(*start==*end)
        {
            start++;
            end--;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}
int main(int argc, const char** argv) {
    string str1,str2,temp;
    int count,len;
    while(cin>>str1>>str2)
    {
        count = 0;
        temp=str1;
        len=str1.length()+1;
        for(int i=0;i<len;i++)
        {
            str1=temp;
            str1.insert(i,str2);   //在A字符串中以此插入B字符串
            if(istrue(str1))       //判断是否是回文
                count=count+1;    //统计回文    
        }
        cout<<count<<endl;
    }
    
    
    return 0;
}


#include <iostream>
using namespace std;
int main(){
    int n,curSum=0,maxSum=-999;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        curSum+=arr[i];
        if(curSum>maxSum){
            maxSum=curSum;
        }
        if(curSum<0){
            curSum=0;
        }
    }
    cout<<maxSum<<endl;
    return 0;
}