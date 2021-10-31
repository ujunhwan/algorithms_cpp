#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

const int maxN = 100000;
const int maxM = 200000;

int N, M, K;
vector<int> adj[maxN+1];

int parent[maxN+1];
bool vst[maxN+1];
int cnt;

void dfs(int x) {
    cnt++;
    vst[x] = true;
    for(int y : adj[x]) {
        if(!vst[y]) {
            dfs(y);
        }
    }
}

void solve() {
    cin >> N >> M >> K;

    int src, dst;
    for(int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        if(i == K) {
            src = u;
            dst = v;
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(src);
    long long p = N-cnt;
    long long q = cnt;
    long long ans = p*q;
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
}

/*
8 9 4
1 2
2 3
4 5
3 4
4 7
5 8
5 7
5 6
6 8
*/