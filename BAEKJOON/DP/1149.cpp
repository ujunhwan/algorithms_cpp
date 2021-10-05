// https://www.acmicpc.net/problem/1149
// 1149번 RGB거리

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int N, a[1111][3], cache[1111][3];

int dp(int idx, int color) {
    if(idx == N) return 0;
    int& ret = cache[idx][color];
    if(ret != -1) return ret;
    ret = INF;

    for(int j = 1; j < 3; j++) {
        if((color+j)%3 == color) continue;
        ret = min(ret, dp(idx+1, (color+j)%3) + a[idx][(color+j)%3]);
    }

    return ret;
}

void solve() {
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    int ans = INF;
    for(int i = 0; i < 3; i++) {
        ans = min(ans, dp(0, i));
    }

    cout << ans << '\n';
}


int main() {
    fastio;
    solve();
}