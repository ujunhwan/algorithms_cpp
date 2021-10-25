// https://www.acmicpc.net/problem/20500
// 20500번 Ezreal 여눈부터 가네 ㅈㅈ

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

const ll MOD = 1000000007;
int N;

ll dp[2000][20];


void solve() {
    cin >> N;

    for(int i = 0; i < 20; i++) {
        dp[0][i] = 0;
        dp[1][i] = 0;
    }

    dp[1][1] = dp[1][5] = 1;
    for(int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][10]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][6]) % MOD;
        dp[i][5] = (dp[i-1][6] + dp[i-1][0]) % MOD;
        dp[i][6] = (dp[i-1][5] + dp[i-1][11]) % MOD;
        dp[i][10] = (dp[i-1][11] + dp[i-1][5]) % MOD;
        dp[i][11] = (dp[i-1][1] + dp[i-1][10]) % MOD;
    }

    int ans = dp[N][0];
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}