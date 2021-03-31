// https://www.acmicpc.net/problem/4811
// 4811번 알약 

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
ll cache[66][33][33];

ll dp(int d, int w, int h) {
    if(d >= 2*n) return 1;
    ll& ret = cache[d][w][h];
    if(ret != -1) return ret;
    ret = 0;
    if(w > 0) ret += dp(d+1, w-1, h+1);
    if(h > 0) ret += dp(d+1, w, h-1);
    return ret;
}

void solve() {
    n = 1;
    while(n != 0) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        if(n == 0) break;
        ll ans = dp(0, n, 0);
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}