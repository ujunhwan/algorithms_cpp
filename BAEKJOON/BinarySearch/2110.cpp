// https://www.acmicpc.net/problem/2110
// 2110번 공유기 설치

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = 0x7f7f7f7f;
int n, c, a[200001];

void solve() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    int l = 0, r = a[n-1];
    int ans = 0;
    while(l <= r) {
        int d = (l + r) / 2;
        long long cnt = 1;

        int pos = 0;
        for(int i = 0; i < n; i++) {
            int oldPos = pos;
            pos = lower_bound(a, a+n, a[pos]+d) - a;
            if(pos >= n) break;
            if(oldPos < pos && pos < n) cnt++;
        }

        if(cnt >= c) {
            l = d + 1;
            ans = d;
        }
        else if (cnt < c) r = d - 1;
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}