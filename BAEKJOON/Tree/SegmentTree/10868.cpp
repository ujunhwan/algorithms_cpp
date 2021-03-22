// https://www.acmicpc.net/problem/10868
// 10868번 최솟값

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;

static const int INF = 0x7f7f7f7f;

int n, m, a[100002];
ll tree[100002 * 4];

ll init(int node, int left, int right) {
    if(left == right) return tree[node] = a[left];

    int mid = (left+right)/2;

    ll leftChild = init(node*2, left, mid);
    ll rightChild = init(node*2+1, mid+1, right);

    return tree[node] = min(leftChild, rightChild);
}

ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
    if(nodeLeft > right || nodeRight < left) return INF;
    if(left <= nodeLeft && nodeRight <= right) return tree[node];

    int mid = (nodeLeft+nodeRight)/2;

    ll leftChild = query(left, right, node*2, nodeLeft, mid);
    ll rightChild = query(left, right, node*2+1, mid+1, nodeRight);

    return min(leftChild, rightChild);
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    init(1, 0, n-1);

    for(int a, b, i = 0; i < m; i++) {
        cin >> a >> b;
        int ans = query(a-1, b-1, 1, 0, n-1);
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}