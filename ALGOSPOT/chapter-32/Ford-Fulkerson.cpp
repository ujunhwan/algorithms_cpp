#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int MAX_V = 500;
int V;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while(true) {
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front();
            q.pop();
            for(int there = 0; there < V; there++) {
                // 잔여용량이 남아있는 애들만 탐색
                // 잔여용량이 남아있으면 증가경로로 설정됨 -> 부모가 정해짐
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        // 증가경로가 존재하지 않을 경우 break
        if(parent[sink] == -1) break;

        int amount = INF;

        // 증가 경로를 통해 얼마나 보낼지 정한다. 
        for(int p = sink; p != source; p = parent[p])
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);

        // 증가경로를 통해 보낸다
        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        totalFlow += amount;
    }

    return totalFlow;
}


int main() {
    return 0;
}