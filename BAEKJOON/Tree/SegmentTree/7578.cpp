// https://www.acmicpc.net/problem/7578
// 7578번 공장

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int N, tree[4*500001];
vector<int> b, c;

ll update(int node, int start, int end, int pos) {
    if(pos < start || pos > end) return tree[node];
    if(start == end) return tree[node] += 1;
    return tree[node] = update(node*2, start, (start+end)/2, pos) + update(node*2+1, (start+end)/2+1, end, pos);
}

ll query(int node, int start, int end, int left, int right) {
    if(start > right || end < left) return 0;
    if(left <= start && end <= right)
        return tree[node];
    return query(node*2, start, (start+end)/2, left, right) + query(node*2+1, (start+end)/2+1, end, left, right);
}

void solve() {
    memset(tree, 0, sizeof(tree));
    cin >> N;
    pii a[1000001];
    vector<pii> d;

    b = vector<int>(N+1);
    c = vector<int>(N+1);

    for(int s, i = 1; i <= N; i++){
        cin >> s;
        b[i] = s;
        a[s].first = i;
    }

    for(int s, i = 1; i <= N; i++){
        cin >> s;
        a[s].second = i;
    }

    for(int i = 1; i <= N; i++) {
        int curr = b[i];
        c[a[curr].first] = a[curr].second;

        // val, idx
        d.emplace_back(-a[curr].second, -a[curr].first);
    }

    sort(d.begin(), d.end());

    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ll cand = query(1, 1, N, 1, -d[i].second);
        ans += cand;
        update(1, 1, N, -d[i].second);
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}