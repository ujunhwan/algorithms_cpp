// https://www.acmicpc.net/problem/11438
// 11438번 LCA 2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

const int maxN = 100000;
const int maxD = 17;

int N, sp[maxD+1][maxN+1], lvl[maxN+1], M;
bool vst[maxN+1];
vector<int> adj[maxN+1];

void dfs(int x) {
    vst[x] = true;
    for(auto y : adj[x]) {
        if(!vst[y]) {
            sp[0][y] = x;
            lvl[y] = lvl[x]+1;
            dfs(y);
        }
    }
}

void solve() {
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(sp, -1, sizeof(sp));
    memset(vst, false, sizeof(vst));
    lvl[1] = 1;
    dfs(1);

    for(int j = 1; j <= maxD; j++) {
        for(int i = 1; i <= N; i++) {
            sp[j][i] = sp[j-1][sp[j-1][i]];
        }
    }

    vector<int> ansList;
    cin >> M;
    while(M--) {
        int p, q;
        cin >> p >> q;
        if(lvl[p] < lvl[q]) {
            swap(p, q);
        }
        int diff = lvl[p] - lvl[q];
        for(int i = 0; diff > 0; i++) {
            if(diff & (1 << i)) {
                diff ^= (1 << i);
                p = sp[i][p];
            }
        }

        if(p != q) {
            for(int i = maxD; i >= 0; i--) {
                if(sp[i][p] != -1 && sp[i][p] != sp[i][q]) {
                    p = sp[i][p];
                    q = sp[i][q];
                }
            }
            p = sp[0][p];
        }

        ansList.push_back(p);
    }

    for(auto ans : ansList) {
        cout << ans << '\n';
    }
}

int32_t main() {
    fastio;
    solve();
}