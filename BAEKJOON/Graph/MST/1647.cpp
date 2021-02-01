// https://www.acmicpc.net/problem/1647
// 1647번 도시 분할 계획

#include <bits/stdc++.h>
using namespace std;

int n, m, parent[100001];
vector<pair<int, pair<int, int> > > edges;

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    parent[u] = v;
}

void solve() {
    for(int i = 0; i <= n; i++)
        parent[i] = i;
    
    int ans = 0;
    int maxc = 0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(find(u) == find(v)) continue;
        merge(u, v);
        ans += cost;
        maxc = max(maxc, cost);
    }

    ans -= maxc;
    printf("%d\n", ans);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int a, b, c, i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back(make_pair(c, make_pair(a, b)));
    }

    solve();
}