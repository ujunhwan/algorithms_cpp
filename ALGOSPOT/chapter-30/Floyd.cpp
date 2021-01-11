#include <bits/stdc++.h>
using namespace std;

const int V = 100;

int c[101][101][101];
int adj[V+1][V+1];

void allPairShortestPath1() {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i != j)
                c[0][i][j] = min(adj[i][j], adj[i][0] + adj[0][j]);
            else
                c[0][i][j] = 0;
        }
    }

    for(int k = 1; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                c[k][i][j] = min(c[k-1][i][j], c[k-1][i][k] + c[k-1][k][j]);
            }
        }
    }
}

void floyd() {
    /* 시간 복잡도 O(V^3), 공간 복잡도 O(V^2) */
    for(int i = 0; i < V; i++)
        adj[i][i] = 0;
    
    // c배열 없이 한번에 계산
    for(int k = 0; k < V; k++) 
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

// u에서 v까지 가는 가는 최단경로가 경유하는 점 중 가장 번호가 큰 점
int via[V][V];

void floyd2() {
    for(int i = 0; i < V; i++)
        adj[i][i] = 0;

    memset(via, -1, sizeof(via));

    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(adj[i][j] > adj[i][k] + adj[k][j]) {
                    via[i][j] = k;
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
}

// u에서 v로 가는 최단 경로를 계산해서 path에 저장한다.
void reconstruct(int u, int v, vector<int> &path) {
    if(via[u][v] == -1) {
        path.push_back(u);
        if(u != v) path.push_back(v);
    }
    
    else {
        int w = via[u][v];
        reconstruct(u, w, path);
        path.pop_back();
        reconstruct(w, v, path);
    }
}