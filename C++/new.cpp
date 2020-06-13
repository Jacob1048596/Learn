#include<iostream>
#include<string>
using namespace std;

// int main()
// {
//     int tmp = 1;
//     string s;
//     cin >> s;
//     int str[26] = { 0 };
//     for (int i = 0; i < s.size(); i++)
//     {
//         str[s[i] - 'a']++;
//     }
//     for (int j = 0; j < s.size(); j++)
//     {
//         if (str[s[j] - 'a'] == 1)
//         {
//             cout<<s[j];
//             tmp=2;
//             break;
//         }
//     }
//     if (tmp == 1)
//     {
//         cout << -1;
//     }
//     return 0;
// }

// int main(int argc, char *argv[])
// {
// 	string a="hello world";
// 	string b=a;
// 	if (a.c_str()==b.c_str())
// 	{
// 		cout<<"true"<<endl;
// 	}
// 	else cout<<"false"<<endl;
// 	string c=b;
// 	c="";
// 	if (a.c_str()==b.c_str())
// 	{
// 		cout<<"true"<<endl;
// 	}
// 	else cout<<"false"<<endl;
// 	a="";
// 	if (a.c_str()==b.c_str())
// 	{
// 		cout<<"true"<<endl;
// 	}
// 	else cout<<"false"<<endl;
// 	return 0;
// }

// int main()
// {
// 	string str("Hello Bit.");
// 	str.reserve(111);
// 	str.resize(5);
// 	str.reserve(50);
// 	cout<<str.size()<<":"<<str.capacity()<<endl;
// 	return 0;
// }

// int main(int argc, char *argv[])
// {
// 	string strText = "How are you?";
// 	string strSeparator = " ";
// 	string strResult;
// 	int size_pos = 0;
// 	int size_prev_pos = 0;
// 	while((size_pos=strText.find_first_of(strSeparator, size_pos)) != string::npos)
// 	{
// 		strResult = strText.substr(size_prev_pos, size_pos-size_prev_pos);
// 		cout<<strResult<<" ";
// 		size_prev_pos = ++size_pos;
// 	}
// 	if(size_prev_pos != strText.size())
// 	{
// 		strResult = strText.substr(size_prev_pos, size_pos-size_prev_pos);
// 		cout<<strResult<<" ";
// 	}
// 	cout<<endl;
// 	return 0;
// }

int main()
{
    string s1("abcdefgh");
    string::iterator begin=s1.begin();
    while (begin!=s1.end())
    {
        /* code */cout<<*begin<<endl;
        begin++;
    }
       string::reverse_iterator rbegin=s1.rbegin();
        while (rbegin!=s1.rend())
    {
        /* code */cout<<*rbegin<<endl;
        rbegin++;
    }
    return 0;
}