// https://www.acmicpc.net/problem/2268
// 2268번 수들의 합 7

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define int long long
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, M, tree[4*1000001], arr[1000001];

int sum(int node, int start, int end, int left, int right) {
    if(start > right || end < left) {
        return 0;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start+end)/2;

    int leftChild = sum(node*2, start, mid, left, right);
    int rightChild = sum(node*2+1, mid+1, end, left, right);

    return leftChild+rightChild;
}

void update(int node, int start, int end, int pos, int diff) {
    if(node <= 0) return;
    if(start > pos || end < pos) return;

    tree[node] += diff;

    if(start == end) {
        return;
    }

    int mid = (start+end)/2;

    update(node*2, start, mid, pos, diff);
    update(node*2+1, mid+1, end, pos, diff);
}

void solve() {
    memset(tree, 0, sizeof(tree));
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;

        if(a == 0) {
            if(b > c) swap(b, c);
            cout << sum(1, 1, N, b, c) << '\n';
        } else {
            update(1, 1, N, b, c - arr[b]);
            arr[b] = c;
        }
    }
}

signed main() {
    fastio;
    solve();
}