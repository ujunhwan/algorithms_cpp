#include <bits/stdc++.h>
using namespace std;

int V;
const int MAX_V = 256;
const int INF = 987654321;

vector<pair<int, int> > adj[MAX_V];

// src에서 모든 정점으 가는 최단거리를 구한다
vector<int> djikstra(int src) {
    vector<int> dist(V, INF);
    dist[src] = 0;
    // 오름차순 정렬을 위해, cost를 마이너스로 저장함
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        // 더 짧은 경로가 이미 존재한다면, 무시
        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            // 새로운 경로가 더 짧다면, 갱신
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    return 0;
}