#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str[100];
    //getline(cin,str);
    int i=0;
    while(cin>>str[i])
    {
        i++;
    }
    while(i+1)
    {
        cout<<str[i];
        if(i!=0) cout<<" ";
        i--;
    }
//     string::iterator it=str.end();
//    for(int i=str.length();i>=0;i--)
//    {
//        cout<<str[i];
//    }
}




#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int> array;
    array.resize(n);
    //读入数组
    int i=0;
    for(i=0;i<n;++i)
        cin>>array[i];
    i=0;
    int k=0;
    int count=0;
    while(i<n)
    {
        if(array[i]<array[i+1] )
        {
            while(array[i]<=array[i+1])
            {
                i++;
            }
            k++;
            i++;
        }
        else if(array[i]==array[i+1])
            i++;
        else
        {
            while(array[i]>=array[i+1])
            {
                i++;
            }
            k++;
            i++;
        }
    }
    cout<<k;
    return 0;
}