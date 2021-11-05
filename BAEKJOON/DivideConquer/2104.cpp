// https://www.acmicpc.net/problem/2104
// 2104번 부분배열 고르기

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define int long long
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, a[100001], psum[100001];

int dfs(int s, int e) {
    if(s > e) return -INF;
    if(s == e) return a[s]*a[s];

    int mid = (s+e)/2;
    int l = mid, r = mid;
    int ret = max(dfs(s, mid), dfs(mid+1, e));
    int val = a[mid], gl = a[mid], gr = a[mid];
    int psum = a[mid], m = a[mid];
    while(s <= l && r <= e) {
        int gl = (l == 0) ? -1 : a[l-1];
        int gr = (r == e) ? -1 : a[r+1];
        if(gl >= gr) {
            psum += a[l-1];
            m = min(m, a[l-1]);
            l -= 1;
        } else {
            psum += a[r+1];
            m = min(m, a[r+1]);
            r += 1;
        }
        ret = max(ret, m*psum);
    }
    return ret;
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(i == 0) {
            psum[i] = a[i];
        } else {
            psum[i] = psum[i-1]+a[i];
        }
    }
    int ans = dfs(0, N-1);
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
}