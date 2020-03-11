// 1373번 2진수 8진수
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string str; cin >> str;
    reverse(str.begin(),str.end());
    int length = str.length();
    while (length % 3 != 0)
    {
        str += '0';
        length += 1;
    }
    int oct = 0;
    string ans;
    for(int i=0;i<=length;i++)
    {
        if(i > 0 && i % 3 == 0)
        {
            ans += to_string(oct);
            oct = 0;
        }
        oct += (str[i] - '0') * pow(2, i % 3);
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
    return 0;
}