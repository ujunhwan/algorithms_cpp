// 15988번 1, 2, 3 더하기 3
#include <bits/stdc++.h>
using namespace std;
long long ans[1000001] = {0, 1, 2, 4};
const long long MOD = 1000000009;
long long func(int n)
{
    if(n <= 0) return 0;
    if(ans[n] > 0) return ans[n];
    for(int i=4;i<=n;i++)
        ans[i] = (ans[i-1] + ans[i-2] + ans[i-3]) % MOD;
    return ans[n];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long t; cin >> t;
    while(t--)
    {
        long long n; cin >> n;
        cout << func(n) << '\n';
    }
}