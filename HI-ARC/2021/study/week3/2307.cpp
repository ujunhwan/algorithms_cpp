// https://www.acmicpc.net/problem/2307
// 2307번 도로검문

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};


int n, m, pre[1001];
vector<pii> adj[1001];

bool isBlocked(pii a, pii b) {
    if(a.first == b.first && a.second == b.second) return true;
    else if(a.first == b.second && a.second == b.first) return true;
    return false;
}

// 1 -> N
int dijkstra(pii edge) {
    vector<pii> inc;
    vector<int> dist(n+1, INF);
    dist[1] = 0;
    priority_queue<pii> pq;
    pq.emplace(0, 1);
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(cost > dist[here]) continue;

        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;

            if(isBlocked(edge, pii(here, there))) continue;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.emplace(-nextDist, there);
                pre[there] = here;
            }
        }
    }

    return dist[n];
}

void solve() {
    cin >> n >> m;
    vector<pii> edge;
    for(int a, b, t, i = 0; i < m; i++) {
        cin >> a >> b >> t;
        adj[a].emplace_back(b, t);
        adj[b].emplace_back(a, t);
    }

    int ans = dijkstra(pii(-1, -1));

    int here = n;

    while(1) {
        if(here == 1) break;
        edge.emplace_back(here, pre[here]);
        here = pre[here];
    }

    int cand = -1;
    for(int i = 0; i < edge.size(); i++)
        cand = max(cand, dijkstra(edge[i]));
    
    ans = cand - ans;

    if(ans >= INF-1000000) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}