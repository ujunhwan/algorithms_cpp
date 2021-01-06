#include <bits/stdc++.h>
using namespace std;
// 책에 있는 코드

int G, H, installed;
vector<int>adj[1001];
vector<bool>visited;

const int INSTALLED = 2;
const int WATCHED = 1;
const int UNWATCHED = 0;

void initializer() {
    for(int i = 0; i < 1001; i++)
        adj[i].clear();
    visited = vector<bool>(G, false);
    installed = 0;
}

int dfs(int here) {
    visited[here] = true;
    int children[3] = {0, 0, 0};
    for(int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if(!visited[there])
            ++children[dfs(there)];
    }

    if(children[UNWATCHED]) {
        ++installed;
        return INSTALLED;
    }

    if(children[INSTALLED])
        return WATCHED;

    return UNWATCHED;
}

int solve() {
    installed = 0;
    for(int u = 0; u < G; u++)
        if(!visited[u] && dfs(u) == UNWATCHED)
            ++installed;
    return installed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int C; cin >> C;
    while(C--) {
        cin >> G >> H;
        initializer();
        for(int i = 0; i < H; i++) {
            int p, q; cin >> p >> q;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
        cout << solve() << '\n';
    }
    return 0;
}