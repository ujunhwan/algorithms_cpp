// https://www.acmicpc.net/problem/1916
// 1916번 최소비용 구하기
 
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef pair<int, int> pii;

const int INF = 987654321*2;

int n, m, src, goal;
vector<pair<int, int> > adj[1001];

int djikstra(int src) {
    vector<int> dist(1001, INF);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextCost = cost + adj[here][i].second;
            if(dist[there] > nextCost) {
                dist[there] = nextCost;
                pq.push(make_pair(-nextCost, there));
            }
        }
    }

    return dist[goal];
}

void solve() {
    cin >> n >> m;
    for(int p, q, w, i = 0; i < m; i++) {
        cin >> p >> q >> w;
        adj[p].push_back(make_pair(q, w));
    }
    cin >> src >> goal;

    int ans = djikstra(src);

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}