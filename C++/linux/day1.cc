#include<iostream>
#include<vector>
#include <algorithm> 
using namespace std;
 
int main()
{
    vector<int> v;
    long long nums;
    cin >> nums;
    v.reserve(3 * nums);
    
    for (size_t i = 0; i < 3 * nums; ++i)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());//排序
    long long sum = 0, j = 0;
    
    // for (int i = (3 * nums) - 2; i >= 0; i -= 2) //1 2 5 5 7 8，每次取 7 5 即可
    // {
    //     if (j < nums)
    //     {
    //         sum += v[i];
    //         ++j;
    //     }
    //     else break;
    // }
     for (int i = nums; i <= 3*nums -2; i = i+2) 
    {
        sum += v[i];
    }
    cout << sum << endl;
    return 0;
}