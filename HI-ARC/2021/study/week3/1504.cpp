// https://www.acmicpc.net/problem/1504
// 1504번 특정한 최단 경로

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int N, E, v1, v2;
vector<pii> adj[801];

ll dijkstra(int src, int goal) {
    vector<ll> dist(N+1, INF);
    dist[src] = 0;
    priority_queue<pii> pq;
    pq.emplace(0, src);
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(cost > dist[here]) continue;

        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.emplace(-nextDist, there);
            }
        }
    }

    return dist[goal];
}

void solve() {
    cin >> N >> E;
    for(int a, b, c, i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    cin >> v1 >> v2;

    ll ans = min(dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N), dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N));
    if(ans > INF-100000) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}