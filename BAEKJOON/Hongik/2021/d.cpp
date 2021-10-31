#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define int long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int N, M;
    cin >> N >> M;

    int k;
    for(int i = 62; i >= 0; i--) {
        if(N & (1LL << i)) {
            k = i;
            break;
        }
    }
    int ans = k+1+M;
    cout << ans << '\n';
}

signed main() {
    fastio;
    int tc; cin >> tc;
    while(tc--)
        solve();
}