// https://www.acmicpc.net/problem/4386
// 4386번 별자리 만들기

#include <bits/stdc++.h>
using namespace std;

int n, parent[101];
typedef struct pos {
    double x, y;
} Pos;
Pos pos[101];
vector<pair<double, pair<int, int> > > edges;

double dist(Pos u, Pos v) {
    return sqrt(pow(u.x - v.x, 2) + pow(u.y - v.y, 2));
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

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &pos[i].x, &pos[i].y);
        for(int j = i - 1; j >= 0; j--) {
            double d = dist(pos[i], pos[j]);
            edges.push_back(make_pair(d, make_pair(i, j)));
        }
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i <= n; i++)
        parent[i] = i;

    double ans = 0;
    for(int i = 0; i < edges.size(); i++) {
        double d = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(find(u) == find(v)) continue;
        merge(u, v);
        ans += d;
    }

    printf("%.2lf\n", ans);
}