// #include<iostream>
// #include<stdio.h>
// using namespace std;
// class level
// {
// private:
//     /* data */
//     int max;
//     int mid;
//     int min;
// public:
//     level(int a=0,int b=0,int c=0);
//     {
//         if(a>b&&a>c&&b>c)
//         {   
//             max=a;
//             mid=b;
//             min=c;
//         }
//         elseif(a>b&&a>c&&b<c)
//         {   
//             max=a;
//             mid=c;
//             min=b;
//         }
//         elseif(b>a&&b>c&&a<c)
//         {   
//             max=b;
//             mid=c;
//             min=a;
//         }
//         else if(b>a&&b>c&&a>c)
//         {    
//             max=b;
//             mid=a;
//             min=c;
//         }
//         else if(c>a&&c>b&&a<b)
//         {   
//             max=c;
//             mid=b;
//             min=a;
//         }
//         elseif(c>a&&c>b&&a>b)
//         {   
//             max=c;
//             mid=a;
//             min=b;
//         }
//     }
//     ~level();
// };


// #include<iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n=0;
//     cin>>n;
//     int temp[300000]={0};
//     for(int i=0;i<(3*n);i++)
//     {
//         cin>>temp[i];
//     }
//     sort(temp,temp+300000);   
//     int mid[100000]={0};
//     for(int i=n,j=0;i<(2*n);i++,j++)
//     {
//         mid[j]=temp[i];
//     }
//     static int ret;
//     for(int i=0;i<n;i++)
//     {
//         ret=ret+mid[i];
//     }
//     cout<<ret<<endl;
        
// }

#include<iostream>
#include<string>
using namespace std;
int main() {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.size(); ++i) {
        for (int j = 0; j < s1.size(); ++j) {
            if (s1[j] == s2[i]) 
            {
                s1.erase(j,1);
            }
        }
    }
    cout << s1 << endl;
    return 0;
}