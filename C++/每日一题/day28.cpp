namespace 猴子分桃
{
    链接：https://www.nowcoder.com/questionTerminal/480d2b484e1f43af8ea8434770811b4a
来源：牛客网

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            continue;
        }
        long a = pow(5, n) - 4;
        long b = pow(4, n) + n - 4;
        cout << a << " " << b << endl;
    }
    return 0;
}
} // namespace 猴子分桃
namespace 奇偶奇偶
{
链接：https://www.nowcoder.com/questionTerminal/b89b14a3b5a94e438b518311c5156366
来源：牛客网

 void oddInOddEvenInEven(vector<int>& arr, int len) {
       int i = 0,j = 1;
       while(i<len&&j<len)
       {
           if(arr[len -1] %2 == 0)
           {
               swap(arr[len -1],arr[i]);
               i+=2;
           }
           else
           {
               swap(arr[len -1],arr[j]);
               j+=2;
           }
       }
    }    链接：https://www.nowcoder.com/questionTerminal/b89b14a3b5a94e438b518311c5156366
来源：牛客网

void oddInOddEvenInEven(vector<int>& arr, int len) {
 int i=0,j=1;
      while(i<len&&j<len){
            if(arr[i]%2!=0&&arr[j]%2==0){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
                i+=2;
                j+=2;
                continue;
            }
            if(arr[i]%2==0)
                i+=2;
            if(arr[j]%2!=0)
                j+=2;
          }
    }
} // namespace 奇偶奇偶

