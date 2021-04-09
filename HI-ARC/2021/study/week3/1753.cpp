// https://www.acmicpc.net/problem/1753
// 1753번 최단 경로

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int V, E, K;
vector<pii> adj[22222];
vector<int> dist;

void solve() {
    cin >> V >> E >> K;
    for(int u, v, w, i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    dist = vector<int> (V+1, INF);
    dist[K] = 0;

    priority_queue<pii> pq;
    pq.emplace(0, K);

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.emplace(-nextDist, there);
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        int ans = dist[i];
        if(ans > INF-100000) cout << "INF" << '\n';
        else cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}