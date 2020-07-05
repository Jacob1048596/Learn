// #include<stdio.h>
// int main()
// {
//     char a=0,ch;
//     while ((ch=getchar())!='\n')
//     {
//         if(a%2!=0&&(ch>='a'&&ch<='z'))
//         ch=ch-'a'+'A';
//         a++;
//         putchar(ch);
//     }
//     printf("\n");
// return 0;
// }
#include<iostream>
using namespace std;
char fun(char x,char y)
{
    if(x<y) return x;
    return y;
}
int main()
{
    int a='1',b='1',c='2';
    cout<<fun(fun(a,b),fun(b,c))<<endl;
}
#include<iostream>
using namespace std;
int a[1000][1000] = {0};
int main()
{
    int w,h,res = 0;
    cin >> w >> h;

    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(a[i][j]==0)
            {
                res++;
                if((i+2)<w) a[i+2][j] = -1;
                if((j+2)<h) a[i][j+2] = -1;
            }
        }
    }
    cout << res;
    return 0;
}

public int StrToInt(String str) {
        if (str == null)
            return 0;
        int result = 0;
        boolean negative = false;//是否负数
        int i = 0, len = str.length();
        /**
         * limit 默认初始化为 负的 最大正整数 ，假如字符串表示的是正数
         * 那么result(在返回之前一直是负数形式)就必须和这个最大正数的负数来比较，
         * 判断是否溢出
         */
        int limit = -Integer.MAX_VALUE;
        int multmin;
        int digit;
 
        if (len > 0) {
            char firstChar = str.charAt(0);//首先看第一位
            if (firstChar < '0') { // Possible leading "+" or "-"
                if (firstChar == '-') {
                    negative = true;
                    limit = Integer.MIN_VALUE;//在负号的情况下，判断溢出的值就变成了 整数的 最小负数了
                } else if (firstChar != '+')//第一位不是数字和-只能是+
                    return 0;
                if (len == 1) // Cannot have lone "+" or "-"
                    return 0;
                i++;
            }
            multmin = limit / 10;
            while (i < len) {
                // Accumulating negatively avoids surprises near MAX_VALUE
                digit = str.charAt(i++)-'0';//char转int
                if (digit < 0 || digit > 9)//0到9以外的数字
                    return 0;
 
                //判断溢出
                if (result < multmin) {
                    return 0;
                }
                result *= 10;
                if (result < limit + digit) {
                    return 0;
                }
                result -= digit;
            }
        } else {
            return 0;
        }
        //如果是正数就返回-result（result一直是负数）
        return negative ? result : -result;
    }