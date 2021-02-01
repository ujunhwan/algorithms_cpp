// https://www.acmicpc.net/problem/6497
// 6497번 전력난

#include <bits/stdc++.h>
using namespace std;

int m, n, parent[200001], ans;
vector<pair<int, pair<int, int> > > edges;

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
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(find(u) == find(v)) continue;
        merge(u, v);
        ans -= cost;
    }

    printf("%d\n", ans);
}

int main() {
    while(1) {
        scanf("%d %d", &m, &n);

        if(m == 0 && n == 0) return 0;

        for(int i = 0; i <= m; i++)
            parent[i] = i;
        edges = vector<pair<int, pair<int, int> > >();
        ans = 0;
        for(int x, y, z, i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            edges.push_back(make_pair(z, make_pair(x, y)));
            edges.push_back(make_pair(z, make_pair(y, x)));
            ans += z;
        }

        solve();
    }
}