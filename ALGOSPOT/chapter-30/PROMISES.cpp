#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 210;
const int INF = 9876543;
int tc, v, m, n;
int adj[MAX_V][MAX_V];

void floyd() {
    for(int i = 0; i < v; i++)
        adj[i][i] = 0;
    
    for(int k = 0; k < v; k++)
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
}

bool update(int a, int b, int c) {
    if(adj[a][b] <= c) return false;

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            adj[i][j] = min(min(adj[i][j], adj[i][a] + c + adj[b][j]), adj[i][b] + c + adj[a][j]);

    return true;
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        for(int i = 0; i < MAX_V; i++)
            for(int j = 0; j < MAX_V; j++)
                adj[i][j] = INF;

        scanf("%d %d %d", &v, &m, &n);
        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            if(adj[a][b] > c)
                adj[a][b] = adj[b][a] = c;
        }

        floyd();

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            if(!update(a, b, c)) ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}