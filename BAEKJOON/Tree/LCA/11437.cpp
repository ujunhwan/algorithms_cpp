// https://www.acmicpc.net/problem/11437
// 11437번 LCA

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

const int maxD = 17;
int N, M;
vector<int> adj[50001], lvl;
vector<bool> vst;
int sp[maxD+1][50001];

void dfs(int x) {
    vst[x] = true;
    for(auto y : adj[x]) {
        if(!vst[y]) {
            sp[0][y] = x;
            lvl[y] = lvl[x]+1;
            dfs(y);
        }
    }
    return;
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
    vst = vector<bool>(N+1, false);
    lvl = vector<int> (N+1);
    lvl[1] = 1;
    dfs(1);

    for(int j = 1; j <= maxD; j++) {
        for(int i = 1; i <= N; i++) {
            sp[j][i] = sp[j-1][sp[j-1][i]];
        }
    }

    vector<int> ansList;    
    cin >> M;
    for(int i = 0; i < M; i++) {
        int p, q;
        cin >> p >> q;
        if(lvl[p] < lvl[q]) {
            swap(p, q);
        }

        // 비트 하나씩 보면서 있을때마다 p의 깊이가 더 깊으니 p를 위로 이동
        int diff = lvl[p]-lvl[q];
        for(int j = 0; diff > 0; j++) {
            if(diff & (1 << j)) {
                diff ^= (1 << j);
                p = sp[j][p];
            }
        }

        // 깊이는 같으나, 노드가 다를 때
        if(p != q) {
            for(int j = maxD; j >= 0; j--) {
                if(sp[j][p] != -1 && sp[j][p] != sp[j][q]) {
                    p = sp[j][p];
                    q = sp[j][q];
                }
            }
            p = sp[0][p];
        }
        ansList.push_back(p);
    }

    for(int ans : ansList) {
        cout << ans << '\n';
    } 
}

int32_t main() {
    fastio;
    solve();
}

/*
15
1 2
1 3
2 4
3 7
6 2
3 8
4 9
2 5
5 11
7 13
10 4
11 15
12 5
14 7
3
1 2
2 3
3 4



6
6 11
10 9
2 6
7 6
8 13
8 15
*/