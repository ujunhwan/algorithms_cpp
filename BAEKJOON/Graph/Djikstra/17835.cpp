// https://www.acmicpc.net/problem/17835
// 17835번 면접보는 승범이네

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static const int INF = 0x7f7f7f7f;

struct Edge {
    int u, v, c;
};

struct cmp {
    bool operator()(pii a, pii b) {
        return a.first > b.first;
    }
};

int N, M, K, dist[100001], parent[100001];
vector<pii> adj[100001];
vector<int> arr;

void solve() {
    memset(dist, 0x7f, sizeof(dist));
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        // adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    priority_queue<pii, vector<pii>, cmp> pq;
    for(int i = 0; i < K; i++) {
        int src;
        cin >> src;
        dist[src] = 0;
        pq.emplace(0, src);
    }

    int cost, here;
    while(!pq.empty()) {
        cost = pq.top().first;
        here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(auto nxt : adj[here]) {
            int there = nxt.first;
            int newDist = nxt.second + cost;
            if(dist[there] > newDist) {
                dist[there] = newDist;
                pq.emplace(newDist, there);
            }
        }
    }

    int maxDist = -1, maxNum = 0;
    for(int i = 1; i <= N; i++) {
        if(maxDist < dist[i]) {
            maxNum = i;
            maxDist = dist[i];
        }
    }
    cout << maxNum << '\n' << maxDist << '\n';
}

int32_t main() {
    fastio;
    solve();
}

/*

*/