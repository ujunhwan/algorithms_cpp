// https://www.acmicpc.net/problem/6213
// 6218번 Balanced Lineup

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define int long long
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, Q, a[50001], A, B, treeMax[4*50001], treeMin[4*50001];

int initMax(int node, int start, int end) {
    if(start == end) {
        return treeMax[node] = a[start];
    }

    int mid = (start+end)/2;
    int lc = initMax(node*2, start, mid);
    int rc = initMax(node*2+1, mid+1, end);
    return treeMax[node] = max(lc, rc);
}

int initMin(int node, int start, int end) {
    if(start == end) {
        return treeMin[node] = a[start];
    }

    int mid = (start+end)/2;
    int lc = initMin(node*2, start, mid);
    int rc = initMin(node*2+1, mid+1, end);
    return treeMin[node] = min(lc, rc);
}

int queryMax(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return -INF;

    if(left <= start && end <= right) {
        return treeMax[node];
    }

    int mid = (start+end)/2;
    int lc = queryMax(node*2, start, mid, left, right);
    int rc = queryMax(node*2+1, mid+1, end, left, right);
    return max(lc, rc);
}

int queryMin(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return INF;

    if(left <= start && end <= right) {
        return treeMin[node];
    }

    int mid = (start+end)/2;
    int lc = queryMin(node*2, start, mid, left, right);
    int rc = queryMin(node*2+1, mid+1, end, left, right);
    return min(lc, rc);
}

void solve() {
    memset(a, 0, sizeof(a));
    memset(treeMax, 0, sizeof(treeMax));
    memset(treeMin, 0, sizeof(treeMin));
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    initMax(1, 1, N);
    initMin(1, 1, N);

    while(Q--) {
        cin >> A >> B;
        int ans = queryMax(1, 1, N, A, B) - queryMin(1, 1, N, A, B);
        cout << ans << '\n';
    }
}

signed main() {
    fastio;
    solve();
}