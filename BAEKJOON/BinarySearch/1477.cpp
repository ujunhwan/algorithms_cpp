// https://www.acmicpc.net/problem/1477
// 1477번 휴게소 세우기

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = 0x7f7f7f7f;

void solve() {
    int n, m, l, a[103];
    cin >> n >> m >> l;
    a[0] = 0; a[n+1] = l;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);

    int lo = 0, hi = INF;
    // (lo, hi], ans = d의 최솟값
    while(lo + 1 < hi) {
        int d = (lo + hi) / 2;
        int rest = 0;
        for(int i = 1; i <= n+1; i++) {
            int delta = a[i] - a[i-1];
            int newRest = delta / d;
            if(delta % d == 0) newRest--;
            rest += newRest;
        }

        // lo -> 조건을 불만족 하는 최댓값
        // hi -> 조건을 만족하는 최솟값
        if(rest > m) lo = d;
        else hi = d;
    }
    int ans = hi;
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}