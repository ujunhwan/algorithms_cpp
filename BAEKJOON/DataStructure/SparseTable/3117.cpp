// https://www.acmicpc.net/problem/3117
// 3117번 YouTube

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, K, M, a[100001], sp[32][100001];

void solve() {
    cin >> N >> K >> M;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= K; i++) {
        cin >> sp[0][i];
    }
    for(int j = 1; j <= 31; j++) {
        for(int i = 1; i <= K; i++) {
            sp[j][i] = sp[j-1][sp[j-1][i]];
        }
    }
    for(int i = 1; i <= N; i++) {
        int cur = a[i];
        for(int j = 31; j >= 0; j--) {
            if((M-1) & (1 << j)) {
                cur = sp[j][cur];
            }
        }
        int ans = cur;
        cout << ans << " ";
    }
    cout << '\n';
}

int32_t main() {
    fastio;
    solve();
}

/*
4 5 2
1 2 4 3
5 5 1 2 3

2 6 5
1 6
2 3 4 1 4 5
*/