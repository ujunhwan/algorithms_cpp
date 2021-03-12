// https://www.acmicpc.net/problem/16964
// 16964번 DFS 스페셜 저지

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

static const int INF = 0x7f7f7f7f;

int n;
vector<int> adj[100001];
vector<int> order, depth;
vector<int> desc;

int dfs(int x, int d) {
    int cnt = 1;
    depth[x] = d;
    for(auto y : adj[x])
        if(!depth[y]) cnt += dfs(y, d+1);
    return desc[x] = cnt;
}

void solve() {
    cin >> n;
    for(int a, b, i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    order = vector<int> (n+1, 0);
    depth = vector<int> (n+1, 0);
    desc = vector<int> (n+1, 0);

    for(int i = 1; i <= n; i++) cin >> order[i];
    
    if(order[1] != 1) {
        puts("0");
        return;
    }

    dfs(order[1], 1);

    for(int i = 1; i <= n; i++) {
        int here = order[i];
        int there = order[i+desc[here]];
        if(there > n || i+desc[here] > n) continue;
        if(desc[here] > 1 && depth[here] < depth[there]) {
            puts("0");
            return;
        }
    }
    puts("1");
}

int main() {
    fastio;
    solve();
}

/*
8
1 2
2 3
3 4
3 8
1 5
5 6
1 7

O
8
1 2
2 3
3 4
3 8
1 5
5 6
1 7
1 2 3 4 8 7 5 6

X
1 2 3 4 6 8 5 7
1 5 3 4 8 2 6 7

*/