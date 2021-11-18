// https://www.acmicpc.net/problem/5676
// 5676번 음주 코딩

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define int long long
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

int N, K, a[100001], tree[100001*4];

int init(int node, int start, int end) {
    if(start == end) {
        if(a[start] == 0) {
            tree[node] = 0;
        } else if(a[start] > 0) {
            tree[node] = 1;
        } else {
            tree[node] = -1;
        }
        return tree[node];
    }

    int mid = (start+end)/2;

    int lc = init(node*2, start, mid);
    int rc = init(node*2+1, mid+1, end);

    return tree[node] = lc*rc;
}

int update(int node, int start, int end, int pos, int val) {
    if(node <= 0) {
        return 1;
    }

    if(!(start <= pos && pos <= end)) {
        return tree[node];
    }

    if(start == end) {
        return tree[node] = val;
    }

    int mid = (start+end)/2;
    int lc = update(node*2, start, mid, pos, val);
    int rc = update(node*2+1, mid+1, end, pos, val);

    return tree[node] = lc*rc;
}

int multiply(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return 1;
    if(left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start+end)/2;
    int lc = multiply(node*2, start, mid, left, right);
    int rc = multiply(node*2+1, mid+1, end, left, right);
    return lc*rc;
}

void solve() {
    memset(a, 0, sizeof(a));
    memset(tree, 0, sizeof(tree));
    cin >> N >> K;
    if(cin.eof()) exit(0);
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    init(1, 1, N);

    char cmd;
    int p, q;
    while(K--) {
        cin >> cmd >> p >> q;
        if(cmd == 'C') {
            //modify
            if(q > 0) {
                q = 1;
            } else if(q < 0) {
                q = -1;
            } else {
                q = 0;
            }
            update(1, 1, N, p, q);
            a[p] = q;
        } else {
            //multiply
            int mul = multiply(1, 1, N, p, q);
            if(mul == 0) {
                cout << "0";
            } else if(mul > 0) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
    }
    cout << '\n';
}

signed main() {
    fastio;
    while(1) {
        solve();
    }
}