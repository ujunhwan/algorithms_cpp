// https://www.acmicpc.net/problem/20647
// 20647번 Cowntagion

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

vector<int> adj[111111];
int n, visited[111111];

int bfs(int src) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    int ans = n-1, log;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        int childSize = 0;
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i];
            if(visited[there] == 0) {
                childSize++;
                visited[there] = 1;
                q.push(there);
            }
        }

        // log(child+1)
        for(log = 0; (1 << log) < childSize+1; log++){}

        ans += log;
    }
    return ans;
}

void solve() {
    cin >> n;
    for(int a, b, i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = bfs(1);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}