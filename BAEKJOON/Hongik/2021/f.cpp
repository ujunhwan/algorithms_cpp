#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

string a;
int N;
int cache[200001][3];

int dp(int idx, int state) {
    if(idx > N) return -INF;
    if(idx == N) {
        if(state == 1) return 0;
        else return -INF;
    }
    int& ret = cache[idx][state];
    if(ret != INF) return ret;
    ret = -INF;

    // 이전 상태
    // 0 -> minus
    // 1 -> number
    // 2 -> plus

    if(state == 0) {
        if(a[idx] == '+') {
            if(a[idx+1] == '-') {
                ret = max(ret, dp(idx+2, 1)-11);
            }
            ret = max(ret, dp(idx+1, 1)-10);
        } else {
            ret = max(ret, dp(idx+1, 1)-1);
        }
    } else if(state == 2) {
        if(a[idx] == '+') {
            if(a[idx+1] == '-') {
                ret = max(ret, dp(idx+2, 1)+11);
            }
            ret = max(ret, dp(idx+1, 1)+10);
        } else {
            ret = max(ret, dp(idx+1, 1)+1);
        }
    } else {
        if(a[idx] == '+') {
            ret = max(ret, dp(idx+1, 2));
        } else {
            ret = max(ret, dp(idx+1, 0));
        }
    }
    return ret;
}

void solve() {
    memset(cache, 0x3f, sizeof(cache));
    cin >> a;
    N = a.size();
    int ans = dp(0, 2);
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
}