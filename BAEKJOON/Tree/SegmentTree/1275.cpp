// https://www.acmicpc.net/problem/1275
// 1275번 커피숍2

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

ll n, q, a[100010];
ll tree[100010*4];

ll init(int start, int end, int node) {
    if(start == end) return tree[node] = a[start];
    return tree[node] = init(start, (start+end)/2, node*2) + init((start+end)/2+1, end, node*2+1);
}

void update(int start, int end, int node, int idx, ll delta) {
    if(idx < start || idx > end) return;
    tree[node] += delta;
    if(start == end) return;
    update(start, (start+end)/2, node*2, idx, delta);
    update((start+end)/2+1, end, node*2+1, idx, delta);
}

ll query(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    return query(start, (start+end)/2, node*2, left, right) + query((start+end)/2+1, end, node*2+1, left, right);
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    init(1, n, 1);

    for(ll x, y, idx, val, i = 0; i < q; i++) {
        cin >> x >> y >> idx >> val;
        if(x > y) swap(x, y);
        ll ans = query(1, n, 1, x, y);
        cout << ans << '\n';

        ll delta = val - a[idx];
        a[idx] = val;
        update(1, n, 1, idx, delta);
    }
}

int main() {
    fastio;
    solve();
}