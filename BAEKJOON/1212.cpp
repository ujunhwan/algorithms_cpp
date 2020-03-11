// 1212번 8진수 2진수
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str; cin >> str;
    string ans = "";
    for(char ch : str)
    {
        int oct = ch - '0';

        if(oct >= 4)
        {
            oct -= 4;
            ans += '1';
        }
        else
            ans += '0';
        if(oct >= 2)
        {
            oct -= 2;
            ans += '1';
        }
        else
            ans += '0';
        if(oct >= 1)
        {
            oct -= 1;
            ans += '1';
        }
        else
            ans += '0';
    }
    while(ans[0] == '0' && ans.length() != 1)
    {
        reverse(ans.begin(),ans.end());
        ans.pop_back();
        reverse(ans.begin(),ans.end());
    }
    cout << ans;
    return 0;
}