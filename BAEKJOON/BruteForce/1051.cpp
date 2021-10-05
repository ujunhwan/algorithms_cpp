// https://www.acmicpc.net/problem/1051
// 1051번 숫자 정사각형

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, m;
string a[55];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    int side = 1;

    int maxLen = min(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 1; k <= maxLen; k++) {
                if(i+k >= n || j+k >= m) continue;
                if(a[i][j] == a[i+k][j+k]) {
                    if(a[i][j] == a[i+k][j] && a[i][j] == a[i][j+k]) side = max(side, k+1);
                }
            }
        }
    }

    int ans = side*side;
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}