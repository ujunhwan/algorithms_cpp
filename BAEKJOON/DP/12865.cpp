// https://www.acmicpc.net/problem/12865
// 12865번 평범한 배낭

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

int n, k, cache[101][100001];
vector<pii> a;

int dp(int idx, int weight) {
    if(idx == n) return 0;
    int& ret = cache[idx][weight];
    if(ret != -1) return ret;
    ret = dp(idx + 1, weight);
    if(weight + a[idx].first <= k)
        ret = max(ret, dp(idx + 1, weight + a[idx].first) + a[idx].second);
    return ret;
}

void solve() {
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    for(int w, v, i = 0; i < n; i++) {
        cin >> w >> v;
        a.emplace_back(w, v);
    }

    int ans = dp(0, 0);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}