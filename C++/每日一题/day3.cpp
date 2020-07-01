// #include<iostream>
// #include<string>
// #include<stdlib.h>
// using namespace std;

// string max_number(string str)
// {
//     string::iterator it = str.begin();

//     int count = 0, max = 0;
//     string s, s_max;
//     while (it != str.end())
//     {
//         while (it != str.end() && (*it > '9' || *it < '0'))
//         {
//             it++;
//         }
//         string::iterator new_it = it;
//         while (it != str.end() && (*it <= '9' && *it >= '0'))
//         {
//             count++;
//             it++;
//         }
//         if (max < count)
//         {
//             while (new_it != it)
//             {
//                 s += *new_it;
//                 new_it++;
//             }

//             max = count;
//             s_max = s;
//             s.clear();
//             count = 0;
//         }
//         else
//             continue;

//     }
//     return s_max;
// }
// int main()
// {
//     string s, s_max;
//     getline(cin,s);
//     s_max = max_number(s);
//     cout << s_max;
//     return 0;
// }
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> arry;
    arry.push_back(100);
    arry.push_back(300);
    arry.push_back(300);
    arry.push_back(300);
    arry.push_back(300);
    arry.push_back(500);
    vector<int>::iterator itor;
    for(itor=arry.begin();itor!=arry.end();itor++)
    {
        if(*itor==300)
            itor=arry.erase(itor);
    }
     for(itor=arry.begin();itor!=arry.end();itor++)
     {
         cout<<*itor<<endl;
     }
    return 0;
}
链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
来源：牛客网

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        // 因为用到了sort，时间复杂度O(NlogN)，并非最优
        if(numbers.empty()) return 0;
         
        sort(numbers.begin(),numbers.end()); // 排序，取数组中间那个数
        int middle = numbers[numbers.size()/2];
         
        int count=0; // 出现次数
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==middle) ++count;
        }
         
        return (count>numbers.size()/2) ? middle :  0;
    }
};
    


// int func()
// {
//     int i,j,k=0;
//     for(i=0,j=-1;j=0;i++,j++)
//     {
//         k++;
//     }
//     return k;
// }
// int main(int argc, char const *argv[])
// {
//    cout<<(func())<<endl;
//     return 0;
// }
