#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 510;
const int INF = 987654321;

int tc, n, m; 
vector<int> x, y;
vector<bool> added;
double adj[MAX_V][MAX_V];

inline double dist(int a, int b) {
    return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}

double prim() {
    const int V = n;
    vector<double> minWeight(V, INF);

    double ret = 0;
    minWeight[0] = 0;

    for(int iter = 0; iter < V; iter++) {
        int u = -1;

        for(int v = 0; v < V; v++)
            if(!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;

        ret += minWeight[u];
        added[u] = true;
        for(int i = 0; i < V; i++)
            if(!added[i])
                minWeight[i] = min(minWeight[i], adj[u][i]);
    }

    return ret;
}

void solve() {
    double ans = prim();

    printf("%.10lf\n", ans);
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        scanf("%d %d", &n, &m);

        x = vector<int> (n);
        y = vector<int> (n);
        added = vector<bool> (n, false);

        for(int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &y[i]);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = dist(i, j);
        
        int a, b;
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            adj[a][b] = adj[b][a] = 0;
        }
        
        solve();
    }

    return 0;
}