链接：https://www.nowcoder.com/questionTerminal/296c2c18037843a7b719cf4c9c0144e4
来源：牛客网

#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int sum = 0, min = arr[0];
        for (int i = 0; i < len; ++i)
        {
            sum += arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < len; ++i)
        {
            for (int j = sum; j >= arr[i]; --j)
            {
                if (dp[j - arr[i]] + arr[i] > dp[j])
                {
                    dp[j] = dp[j - arr[i]] + arr[i];
                }
            }
        }
 
        for (int i = min; i <= sum; ++i)
        {
            if (i != dp[i])
                return i;
        }
        return sum + 1;
    }
};
 
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution s;
        cout << s.getFirstUnFormedNum(a, n) << endl;
    }
    return 0;
}}

链接：https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
来源：牛客网

#include<iostream>
using namespace std;
int main()
{
    int N;
    while(cin>>N&&N)
    {
        int ans=0;
        long long sum=1;
        while(sum<N)
        {
            sum*=3;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}