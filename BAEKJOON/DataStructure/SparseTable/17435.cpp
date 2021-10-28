// https://www.acmicpc.net/problem/17435
// 17435번 합성함수와 쿼리

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

// sp[j][i] -> i번 정점에서 2^j번 이동한 뒤의 정점
// 2^19 ~= 500000 
int m, sp[20][500001], q;

void solve() {
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> sp[0][i];
    }

    for(int j = 1; j < 20; j++) {
        for(int i = 1; i <= m; i++) {
            // 정점 i에서 2^(j+1)번 이동 = 정점 i에서 2^j번 이동한 점에서 2^j번 이동 -> 정점 i에서 2^j*2번 이동
            sp[j][i] = sp[j-1][sp[j-1][i]];
        }
    }

    cin >> q;
    vector<int> vt;
    for(int i = 0; i < q; i++) {
        // 정점 x에서 n번 이동
        int n, x;
        cin >> n >> x;
        int cur = x;
        for(int j = 19; j >= 0; j--) {
            if(n & (1 << j)) {
                cur = sp[j][cur];
            }
        }
        vt.push_back(cur);
    }

    for(auto ans : vt) {
        cout << ans << '\n';
    }
}

int32_t main() {
    fastio;
    solve();
}