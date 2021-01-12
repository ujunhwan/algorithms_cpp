#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 2021;
const int INF = 987654321;

int tc, n, m, V;
vector<int> weights;
vector<pair<int, pair<int, int> > > edges;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n , 1) {
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }

};

int kruskal(int low) {
    DisjointSet sets(V);

    for(int i = 0; i < edges.size(); i++) {
        if(edges[i].first < weights[low]) continue;
        sets.merge(edges[i].second.first, edges[i].second.second);
        if(sets.find(0) == sets.find(V - 1))
            return edges[i].first;
    }

    return INF;
}

void solve() {
    int ans = INF;

    sort(edges.begin(), edges.end());

    for(int i = 0; i < weights.size(); i++)
        ans = min(ans, kruskal(i) - weights[i]);

    printf("%d\n", ans);
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        scanf("%d %d", &n, &m);
        
        edges.clear();
        weights.clear();
        V = n;

        int a, b, c;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back(make_pair(c, make_pair(a, b)));
            edges.push_back(make_pair(c, make_pair(b, a)));
            weights.push_back(c);
        }

        solve();
    }

    return 0;
}