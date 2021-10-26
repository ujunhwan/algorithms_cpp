// https://www.acmicpc.net/problem/2343
// 2343번 기타 레슨

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;

void solve() {
    const ll INF = 0x7f7f7f7f;
    ll n, m, a[100001], maxv;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }

    // (lo, hi]
    ll lo = maxv - 1, hi = INF;
    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll br = 1, len = 0;
        for(int i = 0; i < n; i++) {
            if(len + a[i] <= mid)
                len += a[i];
            else {
                br++;
                len = a[i];
            }
        }
        if(br > m) lo = mid;
        else hi = mid;
    }
    ll ans = hi;
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}