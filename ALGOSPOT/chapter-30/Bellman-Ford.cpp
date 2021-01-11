#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 500;
const int INF = 987654321 * 2;
int V;
vector<pair<int, int> > adj[MAX_V];

vector<int> bellmanFord(int src) {
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool updated;
    // V번 반복
    for(int iter = 0; iter < V; iter++) {
        updated = false;
        for(int here = 0; here < V; here++) {
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if(upper[there] > upper[here] + cost) {
                    // success
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    // 마지막 V번째 반복에서도 완화가 성공한다면 음수사이클 존재
    if(updated) upper.clear();
    return upper;
}

int main() {
    return 0;
}