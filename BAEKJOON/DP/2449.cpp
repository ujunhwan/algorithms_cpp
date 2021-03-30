// https://www.acmicpc.net/problem/2449
// 2449번 전구

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int n, k, cache[222][222];
vector<int> a;

int dp(int l, int r) {
    if(l == r) return 0;
    int& ret = cache[l][r];
    if(ret != -1) return ret;

    ret = INF;

    for(int i = l; i < r; i++)
        ret = min(ret, dp(l, i) + dp(i+1, r) + (a[l] != a[i+1]));

    return ret;
}

void solve() {
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    a = vector<int> (n);
    for(int& el : a) cin >> el;

    int ans = dp(0, n-1);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}