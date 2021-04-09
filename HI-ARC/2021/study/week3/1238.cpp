// https://www.acmicpc.net/problem/1238
// 1238번 파티

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, M, X;

vector<int> djikstra(int src, vector<vector<pii> >& adj) {
    vector<int> dist (N+1, INF);
    priority_queue<pii> pq;

    dist[X] = 0;
    pq.emplace(0, X);

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
    return dist;
}

void solve() {
    cin >> N >> M >> X;

    vector<vector<pii> > f(N+1);
    vector<vector<pii> > r(N+1);

    for(int u, v, t, i = 0; i < M; i++) {
        cin >> u >> v >> t;
        f[u].emplace_back(v, t);
        r[v].emplace_back(u, t);
    }

    vector<int> a = djikstra(X, f);
    vector<int> b = djikstra(X, r);

    int ans = -1;
    for(int i = 1; i <= N; i++) ans = max(ans, a[i]+b[i]);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}