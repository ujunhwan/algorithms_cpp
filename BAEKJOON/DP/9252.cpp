// https://www.acmicpc.net/problem/9252
// 9252번 LCS 2

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

static const int INF = 0x7f7f7f7f;

string a, b, ans;
int n, m, cache[1001][1001];

// aidx, bidx까지 LCS
int dp(int aIdx, int bIdx) {
    if(aIdx == n || bIdx == m) return 0;
    int& ret = cache[aIdx][bIdx];
    if(ret != -1) return ret;

    ret = max(max(dp(aIdx, bIdx+1), dp(aIdx+1, bIdx)), dp(aIdx+1, bIdx+1)+(a[aIdx] == b[bIdx]));
    return ret;
}

void reconstruct(int aIdx, int bIdx) {
    if(aIdx == n || bIdx == m) return;
    if(a[aIdx] == b[bIdx]) {
        ans += a[aIdx];
        reconstruct(aIdx+1, bIdx+1);
    } else if(cache[aIdx+1][bIdx] >= cache[aIdx][bIdx+1]) {
        reconstruct(aIdx+1, bIdx);
    } else {
        reconstruct(aIdx, bIdx+1);
    }
}

void solve() {
    memset(cache, -1, sizeof(cache));
    cin >> a >> b;
    n = a.size(), m = b.size();

    dp(0, 0);
    reconstruct(0, 0);

    cout << (int)ans.size() << '\n' << ans << '\n';
}

int main() {
    fastio;
    solve();
}