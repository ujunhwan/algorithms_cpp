// https://www.acmicpc.net/problem/18877
// 18877번 Social Distancing

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

static const ll INF = 2e+18;

int N, M;
vector<pll> dist;

void solve() {
    cin >> N >> M;
    for(ll a, b, i = 0; i < M; i++) {
        cin >> a >> b;
        dist.push_back(make_pair(a, b));
    }

    sort(dist.begin(), dist.end());

    // [lo, hi)
    ll lo = 1, hi = INF+1;
    while(lo + 1 < hi) {
        ll d = (lo + hi) / 2;
        int rest = N;
        ll nextMin = -1;
        for(int i = 0; i < M; i++) {
            ll start = dist[i].first, end = dist[i].second;
            if(nextMin <= start) {
                rest -= (end-start)/d+1;
            } else if(nextMin <= end) {
                start = nextMin;
                rest -= (end-start)/d+1;
            } else continue;
            nextMin = start + d + (end-start)/d*d;
        }

        if(rest <= 0) lo = d;
        else hi = d;
    }

    ll ans = lo;
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}