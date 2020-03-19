// 2225번 합분해
#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
int main()
{
    long long ans[201][201];
    memset(ans, 0, sizeof(ans));
    int n, k; cin >> n >> k;
    ans[0][0] = 1;
    for(int i=0;i<=n;i++)
        for(int j=1;j<=k;j++)
            for(int l=0;l<=i;l++)
                ans[i][j] = (ans[i][j] + ans[i-l][j-1]) % MOD;
    cout << ans[n][k] << '\n';
}