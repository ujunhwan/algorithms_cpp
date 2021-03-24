// https://www.acmicpc.net/problem/16157
// 16157번 블로그 

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, dp[101][101];
string a;

void solve() {
    cin >> n;
    cin >> a;
    for(int j = 0; j < n; j++) {
        for(int i = j-1; i >= 0; i--) {
            if(a[i] == a[j]) dp[i][j] = max(dp[i][j], dp[i+1][j-1]+1);
            for(int k = i; k <= j; k++) dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]);
        }
    }

    int ans = n-dp[0][n-1];
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}