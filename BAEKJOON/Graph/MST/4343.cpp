// https://www.acmicpc.net/problem/4343
// 4343번 Arctic Network

#include <bits/stdc++.h>
using namespace std;

typedef struct pos {
    int x, y;
} Pos;

typedef struct edge {
    double w;
    int u, v;

    bool operator < (const edge&e) const {
        return w < e.w;
    }
} Edge;

Pos pos[501];
int tc, s, p, parent[501];
vector<Edge> edges;

double dist(Pos u, Pos v) {
    return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
}

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
    for(int i = 0; i <= p; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end());

    int cnt = 0, need = p - s;
    double ans = 0;
    for(int i = 0; i < edges.size(); i++) {
        if(cnt == need) break;
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        double w = edges[i].w;
        if(u == v) continue;
        merge(u, v);
        ans = w;
        cnt++;
    }

    printf("%.2lf\n", ans);
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        edges = vector<Edge>();
        scanf("%d %d", &s, &p);
        for(int i = 0; i < p; i++) {
            scanf("%d %d", &pos[i].x, &pos[i].y);
            for(int j = i - 1; j >= 0; j--) {
                double d = dist(pos[i], pos[j]);
                Edge e = {d, i, j};
                edges.push_back(e);
            }
        }

        solve();
    }
}