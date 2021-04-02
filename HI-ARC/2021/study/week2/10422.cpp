// https://www.acmicpc.net/problem/10422
// 10422번 괄호

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;

static const int mod = 1000000007;

ll dp[5555];

ll dfs(int l) {
    if(l == 0) return 1;
    if(l&1) return 0;
    ll& ret = dp[l];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 2; i <= l; i+=2) {
        ret += (dfs(i-2) * dfs(l-i));
        ret %= mod;
    }

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int tc; cin >> tc;
    while(tc--) {
        int L; cin >> L;
        ll ans = dfs(L);

        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}