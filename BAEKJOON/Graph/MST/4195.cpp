// https://www.acmicpc.net/problem/4195
// 4195번 친구 네트워크

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int parent[200011];
int cnt[200011];

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
    cnt[v] += cnt[u];
    cnt[u] = cnt[v];
}

void solve() {
    int nxt = 0;
    map<string, int> mp;
    int f; cin >> f;
    for(int i = 0; i <= 2*f; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }
    for(int u, v, i = 0; i < f; i++) {
        string n1, n2;
        cin >> n1; cin >> n2;
        if(mp.find(n1) == mp.end()) {
            u = nxt;
            mp.insert(make_pair(n1, nxt++));
        } else u = mp[n1];
        if(mp.find(n2) == mp.end()) {
            v = nxt;
            mp.insert(make_pair(n2, nxt++));
        } else v = mp[n2];

        merge(u, v);
        int ans = cnt[find(u)];
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
}