// https://www.acmicpc.net/problem/2096
// 2096번 내려가기

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int n, a[100001][3];
int dp[2][3];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i < 3; i++) dp[0][i] = a[0][i];
    for(int i = 0; i < n; i++) {
        dp[(i+1)%2][1] = max(max(dp[i%2][0], dp[i%2][1]), dp[i%2][2]) + a[i+1][1];
        dp[(i+1)%2][0] = max(dp[i%2][0], dp[i%2][1]) + a[i+1][0];
        dp[(i+1)%2][2] = max(dp[i%2][1], dp[i%2][2]) + a[i+1][2];
    }
    int ans = max(dp[(n-1)%2][0], max(dp[(n-1)%2][1], dp[(n-1)%2][2]));
    cout << ans << " ";

    memset(dp, 0x7f, sizeof(dp));
    for(int i = 0; i < 3; i++) dp[0][i] = a[0][i];
    for(int i = 0; i < n; i++) {
        dp[(i+1)%2][1] = min(min(dp[i%2][0], dp[i%2][1]), dp[i%2][2]) + a[i+1][1];
        dp[(i+1)%2][0] = min(dp[i%2][0], dp[i%2][1]) + a[i+1][0];
        dp[(i+1)%2][2] = min(dp[i%2][1], dp[i%2][2]) + a[i+1][2];
    }
    ans = min(dp[(n-1)%2][0], min(dp[(n-1)%2][1], dp[(n-1)%2][2]));
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}