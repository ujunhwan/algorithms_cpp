// https://www.acmicpc.net/problem/10942
// 10942번 팰린드롬?

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

int n, m, a[2222], dp[2222][2222];

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) dp[i][i] = 1;

    for(int j = 1; j <= n; j++) {
        for(int i = j-1; i >= 1; i--) {
            if(j - i == 1) {
                dp[i][j] = (a[i] == a[j]) ? 1 : 0;
                continue;
            }
            if(dp[i][j-1] == 1) {
                dp[i][j] = (dp[i+1][j-1] && a[i] == a[j]) == 1 ? 1 : 0;
            } else {
                if(dp[i+1][j-1] == 1 && a[i] == a[j]) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
        }
    }

    cin >> m;
    for(int p, q, i = 0; i < m; i++) {
        cin >> p >> q;
        cout << dp[p][q] << '\n';
    }
}

int main() {
    fastio;
    solve();
}