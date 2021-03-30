// https://www.acmicpc.net/problem/10999
// 10999번 구간 합 구하기 2

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> a, tree, lazy;

ll init(int node, int start, int end) {
    if(start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}

void update(int node, int start, int end, int left, int right, ll num) {
    if(lazy[node] != 0) {
        tree[node] += (end-start+1) * lazy[node];

        // if node is not leaf
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(right < start || left > end) return;

    if(left <= start && end <= right) {
        tree[node] += (end-start+1) * num;
        if(start != end) {
            lazy[node*2] += num;
            lazy[node*2+1] += num;
        }
        return;
    }

    int mid = (start + end) / 2;

    update(node*2, start, mid, left, right, num);
    update(node*2+1, mid+1, end, left, right, num);

    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, int start, int end, int left, int right) {
    if(lazy[node] != 0) {
        tree[node] += (end-start+1) * lazy[node];
        if(start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    if(right < start || left > end) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
}

void solve() {
    cin >> n >> m >> k;

    a = vector<ll> (n+1);
    tree = vector<ll> (4*(n+1));
    lazy = vector<ll> (4*(n+1));

    for(int i = 1; i <= n; i++) cin >> a[i];

    init(1, 1, n);

    for(int a, b, c, i = 0; i < m+k; i++) {
        cin >> a;
        if(a == 1) {
            ll d;
            cin >> b >> c >> d;
            update(1, 1, n, b, c, d);
        } else {
            cin >> b >> c;
            ll ans = query(1, 1, n, b, c);
            cout << ans << '\n';
        }
    }
}

int main() {
    fastio;
    solve();
}