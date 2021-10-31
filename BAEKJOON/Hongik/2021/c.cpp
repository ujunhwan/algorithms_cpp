// https://www.acmicpc.net/problem/c
// c번 

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, K, a[2001];

bool cmp(int a, int b) {
    return a < b;
}

void solve() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    int ans1 = 0;
    for(int i = 2; i <= N; i++) {
        ans1 += (a[i]-a[1]);
    }
    int ans2 = 0;
    for(int i = 1; i <= N; i++) {
        if(a[i] == a[1]) continue;
        ans2++;
    }

    cout << ans1 << " " << ans2 << '\n';
}

signed main() {
    fastio;
    solve();
}