// 1967번 트리의 지름
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
static const int MAX = 10000;
int n, dist[MAX + 1];
vector<pair<int, int> > adj[MAX + 1];
queue<int> q;
pair<int, int> bfs(int x) {
    int ans = 0;
    int idx = 0;
    memset(dist, 0, sizeof(dist));
    q.push(x);
    dist[x] = 1;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            int nxt = adj[x][i].first;
            int cst = adj[x][i].second;
            if (dist[nxt] == 0) {
                q.push(nxt);
                dist[nxt] = dist[x] + cst;
                if (dist[nxt] > ans) {
                    ans = dist[nxt];
                    idx = nxt;
                }
            }
        }
    }
    if(ans != 0) ans -= 1;
    pair<int, int> ret = make_pair(ans, idx);
    return ret;
}
int main () {
    scanf("%d", &n); n--;
    while (n--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }
    pair<int, int> d1 = bfs(1);
    pair<int, int> d2 = bfs(d1.second);
    printf("%d\n", d2.first);
    return 0;
}