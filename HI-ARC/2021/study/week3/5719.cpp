// https://www.acmicpc.net/problem/5719
// 5719번 거의 최단 경로

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

static const int INF = 0x7f7f7f7f;

int N, M, S, D, edge[501][501];
vector<pii> adj[501], rev[501];
vector<ll> dist;

void dijkstra(int src, int goal) {
    dist = vector<ll>(N, INF);
    dist[src] = 0;
    priority_queue<pli> pq;
    pq.emplace(0, src);

    while(!pq.empty()) {
        ll cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(cost > dist[here]) continue;

        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            ll nextDist = adj[here][i].second + cost;
            if(dist[there] > nextDist && edge[here][there]) {
                dist[there] = nextDist;
                pq.emplace(-nextDist, there);
            }
        }
    }
}

void bfs(int src, int goal) {
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(goal);
    visited[goal] = true;

    while(!q.empty()) {
        int here = q.front();
        q.pop();

        if(here == src) continue;
        
        for(int i = 0; i < rev[here].size(); i++) {
            int there = rev[here][i].first;
            int cost = rev[here][i].second;
            if(dist[here] == dist[there] + cost) {
                edge[there][here] = false;
                if(!visited[there]) q.push(there);
                visited[there] = true;
            }
        }
    }
}

void solve() {
    while(1) {
        cin >> N >> M;
        if(N == 0 && M == 0) return;
        cin >> S >> D;

        memset(edge, false, sizeof(edge));
        for(int i = 0; i < N; i++) {
            adj[i].clear();
            rev[i].clear();
        }

        for(int u, v, p, i = 0; i < M; i++) {
            cin >> u >> v >> p;
            edge[u][v] = true;
            adj[u].emplace_back(v, p);
            rev[v].emplace_back(u, p);
        }

        dijkstra(S, D);
        bfs(S, D);
        dijkstra(S, D);

        ll ans = dist[D];
        if(ans > INF-100000) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}

/*
4 5
0 2
0 1 1
0 3 5
1 2 2
1 3 1
3 2 1

ans :
*/