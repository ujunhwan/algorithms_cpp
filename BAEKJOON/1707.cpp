// 1707번 이분 그래프
#include <bits/stdc++.h>
using namespace std;
const int lth = 20001;
vector<int> adj[lth];
int team[lth], n, m;
inline int dfs(int x) {
    for (int i = 0; i < adj[x].size(); i++) {
        int next = adj[x][i];
        if(team[next] == 0) {
            team[next] = 3 - team[x];
            if(dfs(next) == -1) return -1;
        } else if(team[next] == team[x]) return -1;
    }
    return 0;
}
int main(void) {
    int k; scanf("%d\n", &k);   
    while (k--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i ++) {
            adj[i].clear();
            team[i] = 0;
        }
        for (int i = 0; i < m; i ++) {
            int from, to; scanf("%d %d", &from, &to);
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (team[i] == 0) {
                team[i] = 1;
                if (dfs(i) == -1) ans = -1;
            }
        }
        if (ans > -1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}