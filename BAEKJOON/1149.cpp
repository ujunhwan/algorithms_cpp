// 1149번 RGB거리
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int r[n], g[n], b[n];
    int d[n+1][3]; // 0 red 1 green 2 blue
    for(int i=0;i<n;i++)
        cin >> r[i] >> g[i] >> b[i];
    d[0][0] = d[0][1] = d[0][2] = 0;
    for(int i=1;i<=n;i++)
    {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + r[i-1];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + g[i-1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + b[i-1];
    }
    int ans = min(min(d[n][0], d[n][1]), d[n][2]);
    cout << ans << '\n';
}
