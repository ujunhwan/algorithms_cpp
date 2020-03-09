// 10824번 네 수
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string str;
    string upper,lower;
    long long ans;

    for(int i=0;i<4;i++)
    {
        cin >> str;
        if(i<2)
            upper += str;
        else
            lower += str;
    }
    ans = stoll(upper) + stoll(lower);
    cout << ans << '\n';
    return 0;
}