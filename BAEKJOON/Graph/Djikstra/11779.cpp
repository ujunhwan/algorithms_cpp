// https://www.acmicpc.net/problem/11779
// 11779번 최소비용 구하기 2

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int N, M, pre[1001], nxt[1001];
vector<pii> adj[1001];
vector<int> dist;

int dijkstra(int src, int goal) {
    dist = vector<int>(N+1, INF);
    priority_queue<pii> pq;
    pq.emplace(0, src);

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
                pre[there] = here;
            }
        }
    }

    return dist[goal];
}

void solve() {
    memset(pre, -1, sizeof(pre));
    cin >> N >> M;
    for(int a, b, c, i = 0; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    int src, goal;
    cin >> src >> goal;

    int ans = dijkstra(src, goal);
    cout << ans << '\n';

    int here = goal;
    vector<int> trace;
    pre[src] = -1;

    while(here != -1) {
        trace.push_back(here);
        here = pre[here];
    }

    cout << (int)trace.size() << '\n';
    reverse(trace.begin(), trace.end());
    for(auto el : trace) cout << el << " ";
    cout << '\n';
}

int main() {
    fastio;
    solve();
}