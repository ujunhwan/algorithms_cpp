// https://www.acmicpc.net/problem/11438
// 11438번 LCA 2

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

// lca -> [node][log2^k]
int n, m, u, v, lca[100001][18], logn;

vector<int> adj[100001], level, parent;

void bfs(int src) {
    parent = vector<int> (n+1, 0);
    level = vector<int> (n+1, 0);
    level[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];
            if(level[there] == 0) {
                q.push(there);
                level[there] = level[here] + 1;
                parent[there] = here;
            }
        }
    }
}

void solve() {
    memset(lca, 0, sizeof(lca));
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    for(int i = 1; i <= n; i++) lca[i][0] = parent[i];

    for(logn = 1;(1 << logn) <= n; logn++){} logn--;

    for(int j = 1; j <= logn; j++)
        for(int i = 1; i <= n; i++)
            if(lca[i][j-1] != 0) lca[i][j] = lca[lca[i][j-1]][j-1];

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        if(level[u] < level[v]) swap(u, v);

        for(logn = 1; (1 << logn) <= level[u]; logn++) {} logn--;

        for(int j = logn; j >= 0; j--) {
            if(level[u] - pow(2, j) >= level[v])
                u = lca[u][j];
        }

        if(u == v) {
            printf("%d\n", u);
            continue;
        }

        for(int j = logn; j >= 0; j--) {
            if(lca[v][j] != 0 && lca[u][j] != lca[v][j]) {
                u = lca[u][j];
                v = lca[v][j];
            }
        }

        printf("%d\n", parent[v]);
    }
}

int main() {
    solve();
}