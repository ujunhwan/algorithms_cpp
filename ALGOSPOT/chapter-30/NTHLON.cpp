#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int INF = 987654321 * 2;
const int START = 432;
int tc, m, vMax, vMin;
vector<int> a, b, c;

int vertex(int delta) {
    return delta + 200;
}

vector<int> djikstra(int src, vector<pair<int, int> > adj[]) {
    vector<int> dist(456, INF);

    priority_queue<pair<int, int> > pq;
    dist[src] = 0;
    pq.push(make_pair(dist[src], src));

    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(cost > dist[here]) continue;

        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;

            if(nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    return dist;
}

void solve() {
    if(vMax < 0 || vMin > 0) {
        printf("IMPOSSIBLE\n");
        return;
    }

    vector<pair<int, int> > adj[456];

    for(int i = 0; i < c.size(); i++) {
        adj[START].push_back(make_pair(vertex(c[i]), a[i]));
    }

    for(int delta = -200; delta <= 200; delta++) {
        for(int i = 0; i < c.size(); i++) {
            int next = delta + c[i];
            if(next > 200 || next < -200) continue;
            adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
        }
    }

    vector<int> result = djikstra(START, adj);

    if(result[0] == INF) printf("IMPOSSIBLE\n");
    else printf("%d\n", result[vertex(0)]);
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        scanf("%d", &m);

        vMax = -INF;
        vMin = INF;

        a = vector<int> (m + 1);
        b = vector<int> (m + 1);
        c.clear();

        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a[i], &b[i]);
            c.push_back(a[i] - b[i]);
            vMax = max(vMax, c[i]);
            vMin = min(vMin, c[i]);
        }

        solve();
    }
    
    return 0;
}