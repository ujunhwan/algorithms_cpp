#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int n, u, v, vst[3001], cycle[3001], prv[3001], start;
vector<int> adj[3001];
stack<int> s;
queue<int> q;
void dfs() {
    int cur, nxt;
    cur = 1;
    s.push(cur);
    int cnt = 0;
    vst[cur] = ++cnt;
    while(!s.empty()) {
        cur = s.top();
        s.pop();
        int lth = adj[cur].size();
        for (int i = 0; i < lth; i++) {
            nxt = adj[cur][i];
            if (vst[nxt] == 0) {
                prv[nxt] = cur;
                s.push(cur);
                s.push(nxt);
                vst[nxt] = ++cnt;
                break;
            }
            if (prv[cur] != nxt && vst[nxt] < vst[cur]) {
                start = nxt;
                cycle[cur] = 1;
                while (!s.empty()) {
                    cycle[s.top()] = 1;
                    if (start == s.top()) break;
                    s.pop();
                }
                return;
            }
        }
    }
}
void bfs() {
    for (int i = 1; i <= n; i++) {
        if (cycle[i] > 0) 
            q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int lth = adj[cur].size();
        for (int j = 0; j < lth; j++) {
            int nxt = adj[cur][j];
            if (cycle[nxt] == 0) {
                q.push(nxt);
                cycle[nxt] = cycle[cur] + 1;
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    bfs();
    for (int i = 1; i <= n; i++)
        printf("%d ", cycle[i] - 1);
    return 0;
}