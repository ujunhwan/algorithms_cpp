#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_V = 510;
const int INF = 987654;

int tc, v, e; 
int worst[MAX_V][MAX_V], adj[MAX_V][MAX_V];
vector<pair<int, int> > seq;

void floyd() {
    for(int i = 1; i <= v; i++)
        for(int j = 0; j <= v; j++) {
            if(i == j) worst[i][j] = 0;
            else worst[i][j] = adj[i][j];
        }

    for(int k = 1; k <= v; k++)
        for(int i = 1; i <= v; i++)
            for(int j = 1; j <= v; j++) {
                int kk = seq[k].second;
                int tt = seq[k].first;
                adj[i][j] = min(adj[i][j], adj[i][kk] + adj[kk][j]);
                worst[i][j] = min(worst[i][j], adj[i][kk] + adj[kk][j] + tt);
            }
}

void solve() {
    sort(seq.begin(), seq.end());
    floyd();
}

int main() {
    scanf("%d %d", &v, &e);

    for(int i = 0; i < MAX_V; i++)
        for(int j = 0; j < MAX_V; j++) {
            adj[i][j] = INF;
            worst[i][j] = INF;
        }

    seq = vector<pair<int, int> >();
    seq.push_back(make_pair(-INF, 0));

    int p;
    for(int i = 1; i <= v; i++) {
        scanf("%d", &p);
        seq.push_back(make_pair(p, i));
    }

    for(int i = 0; i < e; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a][b] = c;
        adj[b][a] = c;
    }

    solve();

    int s, t;
    for(scanf("%d", &tc); tc--;) {
        scanf("%d %d", &s, &t);
        printf("%d\n", worst[s][t]);
    }

    return 0;
}