// https://www.acmicpc.net/problem/1725
// 1725번 히스토그램

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define int long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, a[100001];

int dfs(int start, int end) {
    if(start > end) return -INF;
    if(start == end) return a[start];
    int mid = (start+end)/2;
    int left = mid, right = mid, height = a[mid], width = 1;
    int ret = max(dfs(start, mid), dfs(mid+1, end));
    while(start <= left && right <= end) {
        int goLeft = -1, goRight = -1;
        if(left > start) {
            goLeft = min(height, a[left-1]);
        }
        if(right < end) {
            goRight = min(height, a[right+1]);
        }

        if(goLeft >= goRight) {
            height = goLeft;
            left -= 1;
        } else {
            height = goRight;
            right += 1;
        }
        ret = max(ret, ++width*height);
    }
    return ret;
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = dfs(0, N-1);
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
}