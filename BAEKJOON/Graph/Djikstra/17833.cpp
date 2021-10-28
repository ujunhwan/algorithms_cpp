// https://www.acmicpc.net/problem/17833
// 17833번 홍익대학교 지하캠퍼스

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x7fffffff;

int N, R, D, M;
vector<int> dist;
vector<pii> adj[2001];

void solve() {
    cin >> N >> R >> D >> M;
    for(int i = 0; i < M; i++) {
        int h, t, e1, e2;
        cin >> h >> t >> e1 >> e2;
        for(int j = 0; j+h <= N; j++) {
            adj[e1+j].push_back(make_pair(t, e2+j));
            adj[e2+j].push_back(make_pair(t, e1+j));
        }
    }

    dist = vector<int> (N+1, INF);
    priority_queue<pii> pq;
    pq.push(make_pair(0, R));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(cost > dist[here] || here == D) continue;

        for(auto nxt : adj[here]) {
            int there = nxt.second;
            int totalTime = nxt.first + cost;
            if(dist[there] > totalTime) {
                dist[there] = totalTime;
                pq.push(make_pair(-totalTime, there));
            }
        }
    }
    int ans = (dist[D] == INF ? -1 : dist[D]);
    cout << ans << '\n';
}

int32_t main() {
    fastio;
    solve();
}