// https://www.acmicpc.net/problem/18324
// 18324번 Race

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 200001;

ll K, N, X;

void solve() {
    cin >> K >> N;
    while(N--) {
        cin >> X;
        int ans = INF;
        int lo = 0, hi = INF;
        // [lo, hi)
        while(lo + 1 < hi) {
            ll mx = (lo+hi)/2;
            ll dist = K;
            ll inc = mx*(mx+1)/2, dec = (mx <= X) ? 0 : inc - X*(X-1)/2;
            ll delta = inc + dec;
            ll fin = min(X, mx);

            // 마지막이 되기 전에 끝나는 경우
            if(dist-(delta-fin) <= 0) {
                hi = mx;
                continue;
            }

            int lt = (dist-delta)/mx;
            int ld = lt*mx;

            int time = (mx <= X) ? mx+lt : mx+(mx-X+1)+lt;

            // cout << mx << " " << inc << " " << dec << '\n';
            // cout << ld << " " << lt << " " << time << '\n';

            if(dist-(delta+ld) > 0) time += 1;

            ans = min(ans, time);
            lo = mx;
        }

        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}