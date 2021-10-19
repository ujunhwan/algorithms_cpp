// https://www.acmicpc.net/problem/23034
// 23034번 조별과제 멈춰!

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

struct edge {
    int u, v, cost;
};

int N, M, Q, parent[1011], maxEdge[1011][1011];
vector<edge> edges;
vector<pii> adj[1011];

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    parent[u] = v;
}

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}

void solve() {
    memset(maxEdge, 0, sizeof(maxEdge));
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), cmp);

    for(int i = 0; i <= N; i++) parent[i] = i;

    int mst = 0;
    for(auto edge : edges) {
        if(find(edge.u) == find(edge.v)) continue;
        merge(edge.u, edge.v);
        adj[edge.u].push_back(make_pair(edge.v, edge.cost));
        adj[edge.v].push_back(make_pair(edge.u, edge.cost));
        mst += edge.cost;
    }

    for(int src = 1; src <= N; src++) {
        vector<int> vst(1011, 0);
        queue<int> q;
        q.push(src);
        vst[src] = 1;
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(auto [nxt, cst]: adj[now]) {
                if(vst[nxt]) continue;
                maxEdge[src][nxt] = max({maxEdge[src][nxt], maxEdge[src][now], cst});
                q.push(nxt);
                vst[nxt] = 1;
            }
        }
    }

    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        int ans = mst - maxEdge[a][b];
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}

/*
4 4
1 2 3
1 3 4
2 3 1
3 4 7
1
1 3

ans : 8
*/