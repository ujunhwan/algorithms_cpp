#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int tc, n, m, V;
int capacity[200][200], flow[200][200];
vector<int> win;

int networkFlow(int src, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;

    while(true) {
        vector<int> parent(200, -1);
        queue<int> q;
        parent[src] = src;
        q.push(src);

        while(!q.empty() && parent[sink] == -1) {
            int here = q.front();
            q.pop();
            for(int there = 0; there < V; there++) {
                int r = capacity[here][there] - flow[here][there];
                if(r > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }

        if(parent[sink] == -1) break;

        int amount = INF;

        for(int p = sink; p != src; p = parent[p]) {
            int r = capacity[parent[p]][p] - flow[parent[p]][p];
            amount = min(amount, r);
        }

        for(int p = sink; p != src; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        totalFlow += amount;
    }
    
    if(capacity[2+m][1] - flow[2+m][1] == 0)
        return totalFlow;
    return -1;
}

void solve() {
    int ans = -1;

    for(int i = win[0]; i <= win[0] + m; i++) {
        int totalWins = i;
        if(*max_element(win.begin() + 1, win.end()) >= totalWins) continue;

        for(int j = 0; j < n; j++) {
            int maxWin = (j == 0 ? totalWins : totalWins - 1);
            capacity[2+m+j][1] = maxWin - win[j];
        }

        V = 2 + m + n;

        if(networkFlow(0, 1) == m) {
            ans = totalWins;
            break;
        }
    }

    printf("%d\n", ans);
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        scanf("%d %d", &n, &m);

        win = vector<int> (n);
        memset(capacity, 0, sizeof(capacity));

        for(int i = 0; i < n; i++)
            scanf("%d", &win[i]);
        
        int a, b;
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            capacity[0][2+i] = 1;
            capacity[2+i][2+m+a] = capacity[2+i][2+m+b] = 1;
        }

        solve();
    }

    return 0;
}