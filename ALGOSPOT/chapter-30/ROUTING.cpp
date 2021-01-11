#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 10000;
const double INF = 1.797679e+308 - 1;
int tc, n, m;

vector<double> djikstra(int src, vector<pair<int, double> >adj[]) {
    vector<double> dist(n, INF);
    dist[src] = 1;
    priority_queue<pair<double, int> > pq;
    pq.push(make_pair(dist[src], src));

    while(!pq.empty()) {
        int here = pq.top().second;
        double cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            double nextDist = dist[here] * adj[here][i].second;
            if(nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    return dist;
}

double solve(vector<pair<int, double> > adj[]) {
    vector<double> ret = djikstra(0, adj);
    return ret[n - 1];
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        vector<pair<int, double> > adj[MAX_N];
        int a, b; double c;

        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++) {
            scanf("%d %d %lf",&a, &b, &c);
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }

        printf("%.10lf\n", solve(adj));
    }

    return 0;
}