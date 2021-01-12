#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;
int V;
vector<pair<int, int> > adj[MAX_V];

int prim(vector<pair<int, int> > &selected) {
    selected.clear();
    // 해당 정점이 트리에 포함되어있는지
    vector<bool> added(V, false);
    // 트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장한다.
    vector<int> minWeight(V, INF), parent(V, -1);
    int ret = 0;
    minWeight[0] = parent[0] = 0;
    for(int iter = 0; iter < V; iter++) {
        // 다음 트리에 추가할 정점 u
        int u = -1;
        for(int v = 0; v < V; v++)
            if(!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        // parent[u], u 를 트리에 추가한다.
        if(parent[u] != u)
            selected.push_back(make_pair(parent[u], u));
        ret += minWeight[u];
        added[u] = true;
        // u에 인접한 간선 (u, v)들을 검사한다.
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first, weight = adj[u][i].second;
            if(!added[v] && minWeight[v] > weight) {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }
    return ret;
}