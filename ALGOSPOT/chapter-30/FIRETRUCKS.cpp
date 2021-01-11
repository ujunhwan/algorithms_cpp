#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

vector<int> fire, station;
const int MAX_N = 1000;
const int INF = 987654321 * 2;
int tc, v, e, n, m;

vector<int> djikstra(vector<pair<int, int> > adj[]) {
    vector<int> dist(v + 1, INF);
    priority_queue<pair<int, int> > pq;

    for(int i = 0; i < station.size(); i++) {
        dist[station[i]] = 0;
        pq.push(make_pair(0, station[i]));
    }

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

int solve(vector<pair<int, int> > adj[]) {
    vector<int> result = djikstra(adj);
    int ret = 0;
    for(int i = 0; i < fire.size(); i++) {
        ret += result[fire[i]];
    }
    return ret;
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        fire.clear(); station.clear();
        vector<pair<int, int> > adj[MAX_N + 1];

        scanf("%d %d %d %d", &v, &e, &n, &m);

        int a, b, t;
        for(int i = 0; i < e; i++) {
            scanf("%d %d %d", &a, &b, &t);
            adj[a].push_back(make_pair(b, t));
            adj[b].push_back(make_pair(a, t));
        }

        for(int i = 0; i < n; i++) {
            scanf("%d", &a);
            fire.push_back(a);
        }

        for(int i = 0; i < m; i++) {
            scanf("%d", &a);
            station.push_back(a);
        }

        printf("%d\n", solve(adj));
    }

    return 0;
}