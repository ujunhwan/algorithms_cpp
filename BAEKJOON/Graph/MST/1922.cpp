// https://www.acmicpc.net/problem/1922
// 1922번 네트워크 연결

#include <bits/stdc++.h>
using namespace std;

const int INF = 20000;
int n, m, parent[1001];
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
    int ans = 0;
    for(int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        // cycle
        if(find(u) == find(v)) continue;
        merge(u, v);
        ans += cost;
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        parent[i] = i;

    for(int a, b, c, i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edges.push_back(make_pair(c, make_pair(a, b)));
    }

    solve();
}