// 11655번 ROT13
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string str; getline(cin,str);
    for(char ch : str)
    {
        if(ch >= 'a' && ch <= 'z')
        {
            if(ch + 13 > 'z')
                ch -= 13;
            else if(ch + 13 <= 'z')
                ch += 13;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            if(ch + 13 > 'Z')
                ch -= 13;
            else if(ch + 13 <= 'Z')
                ch += 13;
        }
        cout << ch;
    }
    cout << '\n';
    return 0;
}