#include<iostream>
using namespace std;
struct Date
{
    char a;
    int b;
    int64_t c;
    char d;
};
int main()
{
    Date a;
    cout<<sizeof(a)*15<<endl;
}
namespace 微信红包
{
    链接：https://www.nowcoder.com/questionTerminal/fbcf95ed620f42a88be24eb2cd57ec54
来源：牛客网

/腾讯笔试题
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        if(gifts.size()<n) return 0;
        if(gifts.size()==0) return 0;
        int count=0,temp;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                temp=gifts[i];
                count=1;
            }
            else{
                if(temp==gifts[i])
                    count++;
                else
                    count--;
            }
        }
        int size=0;
        for(int i=0;i<n;i++){         
            if(temp==gifts[i])
                size++;
        }
        return (size>n/2)?temp:0;
    }
}
} // namespace 微信红包
namespace 计算字符串的距离
{
    链接：https://www.nowcoder.com/questionTerminal/3959837097c7413a961a135d7104c314
来源：牛客网

/典型的动态规划优化编辑器问题
//参考博客 http://blog.csdn.net/shizheng163/article/details/50988023
#include<iostream>
#include <string>
#include <vector>
using namespace std;
int calStringDistance(string a,string b){
    int n = (int)a.size(),m = (int)b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[0][0] = 0;//dp[x][y]代表将a字符串前x个字符修改成b字符串前y个字符
    for (int i=1; i<=m; ++i) dp[0][i] = i;
    for (int i=1; i<=n; ++i) dp[i][0] = i;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            int one = dp[i-1][j] +1,two = dp[i][j-1]+1,three = dp[i-1][j-1];
            if(a[i-1]!=b[j-1]) three+=1;
            dp[i][j] = min(min(one,two),three);
        }
    }
    return dp[n][m];
}
int main(){
    string a,b;
    while(cin>>a>>b)
        cout<<calStringDistance(a, b)<<endl;
    return 0;
}

} // namespace 计算字符串的距离
