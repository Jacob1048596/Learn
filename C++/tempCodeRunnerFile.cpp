#include<iostream>
#include<string>
using namespace std;

int main()
{
    int tmp = 1;
    string s;
    cin >> s;
    int str[26] = { 0 };
    for (int i = 0; i < s.size(); i++)
    {
        str[s[i] - 'a']++;
    }
    for (int j = 0; j < s.size(); j++)
    {
        if (str[s[j] - 'a'] == 1)
        {
            cout<<s[j];
            tmp=2;
            break;
        }
    }
    if (tmp == 1)
    {
        cout << -1;
    }

    return 0;
}
