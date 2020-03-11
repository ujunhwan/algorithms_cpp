// 2089번 -2진수
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//1, 110, 111, 100, 101, 11010, 11011, 11000, 11001 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long N; cin >> N;
    string ans;
    while(N != 0)
    {
        if(N < 0)
        {
            if(N % 2 == -1)
            {
                ans += "1";
                N = N / (-2) + 1;
            }
            else
            {
                ans += "0";
                N = N / (-2);
            }
        }
        else
        {
            ans += to_string(N % 2);
            N = N / (-2);
        }
    }
    reverse(ans.begin(),ans.end());
    if(ans.length () == 0)
        ans += '0';
    cout << ans;
}