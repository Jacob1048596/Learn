// #include<iostream>
// using namespace std;
// struct test
// {
//     /* data */
//     unsigned a:19;
//     unsigned b:11;
//     unsigned c:4;
//     unsigned d:29;
//     char index;
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     cout<<sizeof(test)<<endl;
//     return 0;
// }
// 链接：https://www.nowcoder.com/questionTerminal/ee5de2e7c45a46a090c1ced2fdc62355
// 来源：牛客网

#include <iostream>
#include <string>
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{
    string s1, s2;
    cin >> s2;
    while (cin >> s1)
        s2 = s1  + " " + s2;
    cout << s2 << endl;
    return 0;
}
// 链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
// 来源：牛客网

#include<stdio.h>
int main(){
    int a[100001],i,n,flag=0,res=1;
    for(scanf("%d",&n),i=0;i<n;i++) scanf("%d",a+i);
    for(i=1;i<n-1;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]
           ||a[i]<a[i-1]&&a[i]<a[i+1]){
            res++;
            if(n-3!=i) i++;
        }
    }
    printf("%d\n",res);
}//找出波峰波谷
