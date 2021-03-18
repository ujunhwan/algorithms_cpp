// https://www.acmicpc.net/problem/2533
// 2533번 사회망 서비스(SNS)

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;

vector<int> adj[1000001];
int n, visited[1000001], ans;

vector<int> ea;

int dfs(int x) {
    visited[x] = 1;
    int ret = -1;
    bool should = false;
    for(int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i];
        if(!visited[y]) {
            ret = dfs(y);
            if(ret == 2 || ret == 0) {
                ea.push_back(x);
                if(visited[x] != -1) ans++;
                visited[x] = -1;
                should = true;
            }
        }
    }

    if(should) return 1;
    else if(ret == -1) return 2;
    return 0;
}

void solve() {
    memset(visited, 0, sizeof(visited));
    cin >> n;
    for(int u, v, i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
}