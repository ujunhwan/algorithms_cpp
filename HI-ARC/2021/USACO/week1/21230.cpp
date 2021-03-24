// https://www.acmicpc.net/problem/21230
// 21230번 Modern Art 3

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, a[321], dp[321][321];

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int j = 0; j < n; j++) {
        for(int i = j-1; i >= 0; i--) {
            if(a[i] == a[j]) 
                dp[i][j] = max(dp[i][j], dp[i+1][j-1]+1);

            for(int k = i; k <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }

    int ans = n-dp[0][n-1];
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}