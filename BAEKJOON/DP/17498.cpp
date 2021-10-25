// https://www.acmicpc.net/problem/17498
// 17498번 폴짝 게임

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const ll INF = 1e+12;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

ll n, m, d;
ll a[200011], cache[200011];

ll dp(int pos) {
    int row = pos/m;
    int col = pos%m;

    if(row == n-1) return 0;
    if(row > n-1) return -INF;

    ll& ret = cache[pos];
    if(ret != -INF) return ret;
    ret = -INF;

    for(int i = row+1; i <= row+d; i++) {
        for(int j = col-d; j <= col+d; j++) {
            if(i >= 0 && j >= 0 && i < n && j < m) {
                if(abs(row-i)+abs(col-j) <= d) {
                    ret = max(ret, dp(i*m+j)+a[pos]*a[i*m+j]);
                }
            }
        }
    }

    return ret;
}

void solve() {
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i*m+j];
            cache[i*m+j] = -INF;
        }
    }

    ll ans = -INF;
    for(int i = 0; i < m; i++) {
        ans = max(ans, dp(i));
    }
    
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}