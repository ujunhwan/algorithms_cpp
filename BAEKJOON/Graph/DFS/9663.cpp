// https://www.acmicpc.net/problem/9663
// 9663번 N-Queen

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, x[50], incr[50], decr[50];

int dfs(int y) {
    if(y >= n) return 1;
    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] || incr[n+y-i] || decr[y+i]) continue;
        x[i] = incr[n+y-i] = decr[y+i] = 1;
        ret += dfs(y+1);
        x[i] = incr[n+y-i] = decr[y+i] = 0;
    }
    return ret;
}

void solve() {
    cin >> n;
    memset(x, 0, sizeof(x));
    memset(incr, 0, sizeof(x));
    memset(decr, 0, sizeof(x));
    int ans = dfs(0);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}