#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 987654321 * 2;
const int M = 9876543;
int tc, g, w, a, b, d;

vector<pair<int, int> > adj[1001];
bool reachable[101][101];

int bellmanFord(int src, int target) {
    vector<int> upper(g, INF);
    upper[src] = 0;

    for(int iter = 0; iter < g - 1; iter++)
        for(int here = 0; here < g; here++)
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                upper[there] = min(upper[there], upper[here] + cost);
            }
    
    for(int here = 0; here < g; here++)
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int cost = adj[here][i].second;

            if(upper[there] > upper[here] + cost)
                if(reachable[src][here] && reachable[here][target])
                    return -INF;
        }

    return upper[target];
}

void solve() {
    // floyd
    for(int i = 0; i < g; i++)
        for(int j = 0; j < g; j++)
            for(int k = 0; k < g; k++)
                reachable[j][k] |= reachable[j][i] && reachable[i][k];
    
    if(!reachable[0][1]) {
        printf("UNREACHABLE\n");
        return;
    }

    int p1 = bellmanFord(0, 1);

    if(p1 == -INF) printf("INFINITY ");
    else if(p1 >= INF - M) {
        printf("UNREACHABLE\n");
        return;
    }
    else printf("%d ", p1);

    for(int i = 0; i < g; i++)
        for(int j = 0; j < adj[i].size(); j++)
            adj[i][j].second = -adj[i][j].second;

    int p2 = bellmanFord(0, 1);

    if(p2 == -INF) printf("INFINITY\n");
    else printf("%d\n", -p2);
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        scanf("%d %d", &g, &w);

        memset(reachable, false, sizeof(reachable));
        for(int i = 0; i < 1001; i++)
            adj[i].clear();

        for(int i = 0; i < w; i++) {
            scanf("%d %d %d", &a, &b, &d);
            adj[a].push_back(make_pair(b, d));
            reachable[a][b] = true;
        }

        solve();
    }

    return 0;
}