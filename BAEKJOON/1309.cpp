// 1309번 동물원
#include <bits/stdc++.h>
using namespace std;
const long long mod = 9901;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n; cin >> n;
    long long d[n+1][3]; // 0 empty 1 left 2 right
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
    for(int i=2;i<=n;i++)
    {
        d[i][0] = (d[i-1][1] + d[i-1][2] + d[i-1][0]) % mod;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % mod;
        d[i][2] = (d[i-1][0] + d[i-1][1]) % mod;
    }
    long long ans = (d[n][0] + d[n][1] + d[n][2]) % mod;
    cout << ans << '\n';
}