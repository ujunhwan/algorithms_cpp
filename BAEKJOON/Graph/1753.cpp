// https://www.acmicpc.net/problem/1753
// 1753번 최단경로

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int v, e, k;
vector<pair<int, int> > adj[20000+2];

void solve() {
    vector<int> dist(v+1, INF);
    dist[k] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, k));
    while(!pq.empty()) {
        int c = -pq.top().first;
        int h = pq.top().second;
        pq.pop();
        if(dist[h] < c) continue;
        for(int i = 0; i < adj[h].size(); i++) {
            int nxt = adj[h][i].first;
            int cst = adj[h][i].second + c;
            if(dist[nxt] > cst) {
                dist[nxt] = cst;
                pq.push(make_pair(-cst, nxt));
            }
        }
    }

    for(int i = 1; i <= v; i++) {
        if(dist[i] > INF - 100000) {
            puts("INF");
            continue;
        }
        printf("%d\n", dist[i]);
    }
}

int main() {
    scanf("%d %d %d", &v, &e, &k);
    for(int a, b, w, i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &w);
        adj[a].push_back(make_pair(b, w));
    }
    solve();
}