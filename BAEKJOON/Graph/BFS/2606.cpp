// https://www.acmicpc.net/problem/2606
// 2606번 바이러스

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, M;
vector<int> adj[111];

void solve() {
    cin >> N >> M;
    for(int u, v, i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vst(111, 0);
    queue<int> q;
    q.push(1);
    vst[1] = 1;
    int ans = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now != 1) ans++;
        for(auto nxt : adj[now]) {
            if(vst[nxt]) continue;
            vst[nxt] = 1;
            q.push(nxt);
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}