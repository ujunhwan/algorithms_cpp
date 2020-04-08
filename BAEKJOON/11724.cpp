// 11724번 연결 요소의 개수
#include <cstdio>
#include <vector>
std::vector<int> adj[1000];
bool check[1001];
void dfs(int x) {
    check[x] = true;
    for (int i = 0; i < adj[x].size(); i++) {
        if (!check[adj[x][i]])
            dfs(adj[x][i]);
    }
}
int main() {
    int n,m; scanf("%d %d", &n, &m);   
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int comp = 0;
    for (int i = 1; i <= n; i ++) {
        if (!check[i]) {
            dfs(i); comp++;
        }
    }
    printf("%d\n", comp);
    return 0;
}