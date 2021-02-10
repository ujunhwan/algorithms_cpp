// https://www.acmicpc.net/problem/15976
// 15976번 XCorr

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;

void solve() {
    int N, M, a, b;
    cin >> N;
    vector<ll> xind(N), xval(N);
    for(int i = 0; i < N; i++) cin >> xind[i] >> xval[i];
    
    cin >> M;
    vector<ll> yind(M), yval(M), psum(M+1, 0);
    for(int i = 0; i < M; i++) {
        cin >> yind[i] >> yval[i];
        psum[i+1] = psum[i] + yval[i];
    }
    yind.push_back(1e+18);
    cin >> a >> b;

    ll ans = 0;
    for(int i = 0; i < N; i++) {
        int hi = upper_bound(yind.begin(), yind.end(), xind[i]+b) - yind.begin();
        int lo = lower_bound(yind.begin(), yind.end(), xind[i]+a) - yind.begin();
        ans += (psum[hi] - psum[lo]) * xval[i];
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}