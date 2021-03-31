// https://www.acmicpc.net/problem/2662
// 2662번 기업투자 

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

static const int INF = 0x7f7f7f7f;

int n, m, cache[333][22], a[333][22], invest[333][22];

// 남은돈 money, idx번째 회사에 투자할 차례
int dp(int money, int idx) {
    if(idx > m) return 0;
    int& ret = cache[money][idx];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i <= money; i++) {
        int cand = dp(money-i, idx+1) + a[i][idx];
        if(ret < cand) {
            ret = cand;
            invest[money][idx] = i;
        }
    }

    return ret;
}

void reconstruct(int money, int idx) {
    if(idx > m) return;
    cout << invest[money][idx] << " ";
    reconstruct(money - invest[money][idx], idx+1);
}

void solve() {
    memset(cache, -1, sizeof(cache));
    memset(a, 0, sizeof(a));
    cin >> n >> m;

    for(int p, i = 0; i < n; i++) {
        cin >> p;
        for(int j = 1; j <= m; j++)
            cin >> a[p][j];
    }
    
    int ans = dp(n, 1);
    cout << ans << '\n';

    reconstruct(n, 1);
    cout << '\n';
}

int main() {
    fastio;
    solve();
}