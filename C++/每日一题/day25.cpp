#include<iostream>
using namespace std;
int main()
{

}
namespace shugen
{
    #include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        int num =0;
        //先将每一位进行相加得到总和，防止数字过大
        for(int i = 0; i < str.size(); ++i){
            num += str[i] - '0';
        }
        int sum = 0;
        while(num)
        {
            sum += num % 10;
            num /= 10;
            if(num == 0 && sum / 10 != 0)
            {
                num = sum;
                sum = 0;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
} // namespace shugen

namespace xingjimima
{
    链接：https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
来源：牛客网

#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {1, 1};
    for(int i = 2; i < 10001; ++i){
        v.push_back((v[i - 2] + v[i - 1]) % 10000);
    }
    int n, x;
    while(cin >> n){
        for(int i = 0; i < n; ++i){
            cin >> x;
            printf("%04d", v[x]);
        }
        printf("\n");
    }
    return 0;
}
}