// https://www.acmicpc.net/problem/14427
// 14428번 수열과 쿼리 16

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

struct T {
    int val, pos;
};

int N, a[100001], M; 
T tree[4*100001];

T init(int node, int start, int end) {
    if(start == end) {
        return tree[node] = {a[start], start};
    }
    int mid = (start+end)/2;
    T lc = init(node*2, start, mid);
    T rc = init(node*2+1, mid+1, end);

    if(lc.val > rc.val) {
        return tree[node] = rc;
    } else if(lc.val < rc.val) {
        return tree[node] = lc;
    } else {
        if(lc.pos > rc.pos) {
            return tree[node] = rc;
        } 
        return tree[node] = lc;
    }
}

T query(int node, int start, int end, int left, int right) {
    if(start > right || end < left) {
        return {INF, INF};
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start+end)/2;
    T lc = query(node*2, start, mid, left, right);
    T rc = query(node*2+1, mid+1, end, left, right);
    if(lc.val > rc.val) {
        return rc;
    } else if(lc.val < rc.val) {
        return lc;
    } else {
        if(lc.pos > rc.pos) {
            return rc;
        }
        return lc;
    }
}

T update(int node, int start, int end, int pos, int val) {
    if(!(start <= pos && pos <= end)) {
        return tree[node];
    }

    if(start == end) {
        tree[node].val = val;
        return tree[node];
    }

    int mid = (start+end)/2;
    T lc = update(node*2, start, mid, pos, val);
    T rc = update(node*2+1, mid+1, end, pos, val);
    if(lc.val > rc.val) {
        return tree[node] = rc;
    } else if(lc.val < rc.val) {
        return tree[node] = lc;
    } else {
        if(lc.pos > rc.pos) {
            return tree[node] = rc;
        }
        return tree[node] = lc;
    }
}

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    init(1, 1, N);
    cin >> M;
    while(M--) {
        int cmd;
        cin >> cmd;
        if(cmd == 1) {
            int b, c;
            cin >> b >> c;
            update(1, 1, N, b, c);
            a[b] = c;
        } else {
            int b, c;
            cin >> b >> c;
            T ans = query(1, 1, N, b, c);
            cout << ans.pos << '\n';
        }
    }
}

signed main() {
    fastio;
    solve();
}