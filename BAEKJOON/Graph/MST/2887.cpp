// https://www.acmicpc.net/problem/2887
// 2887번 행성 터널

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int d, u, v;

    Edge(int d, int u, int v) : d(d), u(u), v(v) {}
    bool operator < (const Edge e) const {
        return d < e.d;
    }
};

int n, parent[100001], rnk[100001];
vector<Edge> edges;
vector<pair<int, int> > x, y, z;

inline int dist(int u, int v) {
    return abs(u - v);
}

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(rnk[u] > rnk[v]) swap(u, v);
    parent[u] = v;
    if(rnk[u] == rnk[v]) rnk[v]++;
}

void solve() {
    for(int i = 0; i <= n; i++)
        parent[i] = i, rnk[i] = 1;
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for(int i = 0; i < n - 1; i++) {
        edges.push_back(Edge(dist(x[i + 1].first, x[i].first), x[i + 1].second, x[i].second));
        edges.push_back(Edge(dist(y[i + 1].first, y[i].first), y[i + 1].second, y[i].second));
        edges.push_back(Edge(dist(z[i + 1].first, z[i].first), z[i + 1].second, z[i].second));
    }
    
    sort(edges.begin(), edges.end());
    
    int ans = 0, cnt = 0;

    for(int i = 0; i < edges.size(); i++) {
        int d = edges[i].d;
        int u = edges[i].u, v = edges[i].v;
        if(find(u) == find(v)) continue;
        merge(u, v);
        cnt++;
        ans += d;
        if(cnt == n - 1) {
            printf("%d\n", ans);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int a, b, c, i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        x.push_back(make_pair(a, i));
        y.push_back(make_pair(b, i));
        z.push_back(make_pair(c, i));
    }

    solve();
}