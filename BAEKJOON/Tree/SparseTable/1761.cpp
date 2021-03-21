// https://www.acmicpc.net/problem/1761
// 1761번 정점들의 거리

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

int n, m, logn, lca[40010][17];
vector<int> parent, level, dist;
vector<pii> adj[40010];

void bfs(int src) {
    parent = vector<int> (n+1, 0);
    parent[src] = 0;
    level = vector<int> (n+1, 0);
    level[src] = 1;
    dist = vector<int> (n+1, 0);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int here = q.front();
        q.pop();

        int there, cost;
        for(int i = 0; i < adj[here].size(); i++) {
            tie(there, cost) = adj[here][i];
            if(level[there] == 0) {
                parent[there] = here;
                level[there] = level[here] + 1;
                dist[there] = dist[here] + cost;
                q.push(there);
            }
        }
    }
}

void solve() {
    memset(lca, 0, sizeof(lca));
    cin >> n;
    for(int u, v, w, i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    bfs(1);

    for(logn = 1; (1 << logn) <= n; logn++) {} logn--;

    for(int u = 1; u <= n; u++) lca[u][0] = parent[u];

    for(int k = 1; k <= logn; k++)
        for(int u = 1; u <= n; u++)
            if(lca[u][k-1] != 0)
                lca[u][k] = lca[lca[u][k-1]][k-1];

    cin >> m;
    for(int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        int ud = dist[u], uv = dist[v];

        // level u > level v
        if(level[u] < level[v]) swap(u, v);

        // level u == level v
        for(logn = 1; (1 << logn) <= level[u]; logn++) {} logn--;
        for(int j = logn; j >= 0; j--)
            if(level[u] - pow(2, j) >= level[v])
                u = lca[u][j];

        if(u != v) {
            for(int j = logn; j >= 0; j--) {
                if(lca[u][j] != 0 && lca[u][j] != lca[v][j]) {
                    u = lca[u][j];
                    v = lca[v][j];
                }
            }
            u = lca[u][0];
        }

        int ans = ud + uv - 2*dist[u];
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}