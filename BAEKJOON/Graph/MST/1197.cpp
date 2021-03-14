// https://www.acmicpc.net/problem/1197
// 1197번 최소 스패닝 트리

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

struct edge {
    int u, v, w;
};

int v, e, parent[10001];

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
}

void solve() {
    cin >> v >> e;
    vector<edge> edges(e);

    for(int u, v, w, i = 0; i < e; i++) {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    for(int i = 0; i < v; i++) parent[i] = i;

    sort(edges.begin(), edges.end(), cmp);

    int ans = 0;
    for(int i = 0; i < e; i++) {
        int weight = edges[i].w;
        int u = edges[i].u, v = edges[i].v;
        if(find(u) == find(v)) continue;
        merge(u, v);
        ans += weight;
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}