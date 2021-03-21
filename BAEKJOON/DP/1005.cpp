// https://www.acmicpc.net/problem/1005
// 1005번 ACM Craft

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, k, d[1001], w;
int cache[1001];
vector<int> a[1001];

int dfs(int idx) {
    if(a[idx].size() == 0) return d[idx];
    int& ret = cache[idx];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < a[idx].size(); i++) {
        int prev = a[idx][i];
        ret = max(ret, dfs(prev) + d[idx]);
    }
    return ret;
}

void solve() {
    int tc; cin >> tc;
    while(tc--) {
        memset(d, 0, sizeof(d));
        memset(cache, -1, sizeof(cache));
        cin >> n >> k;
        for(int i = 1; i <= n; i++) a[i] = vector<int>();
        for(int i = 1; i <= n; i++) cin >> d[i];
        for(int x, y, i = 0; i < k; i++) {
            cin >> x >> y;
            a[y].push_back(x);
        }
        cin >> w;

        int ans = dfs(w);
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}