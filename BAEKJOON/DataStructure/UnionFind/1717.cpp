// https://www.acmicpc.net/problem/1717
// 1717번 집합의 표현

#include <bits/stdc++.h>
using namespace std;

int n, m, cal, a, b;
int parent[1000001];

// 0 union, 1 find

int find(int u) {
    if(u < 0) return -1;
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    parent[u] = v;
}

void solve() {
    if(cal == 0) {
        merge(a, b);
        return;
    }
    find(a) == find(b) ? puts("YES") : puts("NO");
}

int main() {
    for(int i = 0; i < 1000001; i++)
        parent[i] = i;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &cal, &a, &b);
        solve();
    }
}