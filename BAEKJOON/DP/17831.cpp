// https://www.acmicpc.net/problem/17831
// 17831번 대기업 승범이네

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

static const int INF = 0x7f7f7f7f;

int n, val[200001], visited[200001];
ll dp[200001][2];
vector<int> adj[200001];

void dfs(int x) {
    visited[x] = 1;

    // leaf
    if(adj[x].size() == 0) return;

    ll cand = 0;
    for(int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i];
        if(!visited[y]) {
            dfs(y);
            // 본인이 부모에게 묶이지 않은 상황
            dp[x][0] += dp[y][0];

            // 본인이 부모에게 묶인 상황
            dp[x][1] += dp[y][0];
        }
    }

    for(int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i];
        cand = max(cand, dp[x][0] - dp[y][0] + dp[y][1] + val[x]*val[y]);
    }
    cand = max(cand, dp[x][1]);

    dp[x][0] = cand;
}

void solve() {
    memset(val, 0, sizeof(val));
    memset(visited, 0, sizeof(visited));
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int p, i = 2; i <= n; i++) {
        cin >> p;
        adj[p].push_back(i);
    }
    for(int i = 1; i <= n; i++) cin >> val[i];

    dfs(1);

    int ans = max(dp[1][0], dp[1][1]);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}