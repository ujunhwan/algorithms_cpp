// https://www.acmicpc.net/problem/22983
// 22983번 조각 체스판

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

ll n, m, dp[3011][3011];
string a[3011];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0) continue;
            if(a[i][j] == a[i-1][j-1]) {
                if(a[i][j] != a[i-1][j] && a[i][j] != a[i][j-1]) {
                    dp[i][j] += min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += dp[i][j];
        }
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}