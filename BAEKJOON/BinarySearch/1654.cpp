// https://www.acmicpc.net/problem/1654
// 1654번 랜선 자르기 

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

const int maxK = 10000;
const int maxN = 1000000;

ll K, N, a[maxK];

bool cmp(ll a, ll b) {
    return a < b;
}

void solve() {
    cin >> K >> N;
    for(int i = 0; i < K; i++) cin >> a[i];
    sort(a, a+K, cmp);
    ll lo = 1, hi = a[K-1]+1;

    // [lo, hi)
    while(lo + 1 < hi) {
        ll mid = (lo+hi)/2;
        ll cand = 0; 

        // cout << lo << " " << mid << " " << hi << '\n';

        for(int i = 0; i < K; i++) {
            cand += a[i]/mid;
        }

        if(cand >= N) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    ll ans = lo;
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}