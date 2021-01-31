// https://www.acmicpc.net/problem/11404
// 11404번 플로이드

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, adj[101][101];

void floyd() {
    for(int i = 0; i < n; i++)
        adj[i][i] = 0;

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(adj[i][j] == INF) adj[i][j] = 0;
}

void solve() {
    floyd();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = INF;
    for(int a, b, c, i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a-1][b-1] = min(adj[a-1][b-1], c);
    }

    solve();
}