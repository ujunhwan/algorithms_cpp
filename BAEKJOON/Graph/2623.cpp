// https://www.acmicpc.net/problem/2623
// 2623번 음악프로그램

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> adj[1002];
int ind[1002];

void solve() {
    queue<int> q;
    vector<int> result;
    for(int i = 1; i <= n; i++)
        if(ind[i] == 0)
            q.push(i);
    
    for(int i = 1; i <= n; i++) {
        if(q.empty()) {
            puts("0");
            return;
        }

        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for(int nxt : adj[curr])
            if(--ind[nxt] == 0)
                q.push(nxt);
    }

    for(int i = 0; i < result.size(); i++)
        printf("%d\n", result[i]);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int s, af = 0;
        scanf("%d", &s);
        for(int j = 0; j < s; j++) {
            int bf = af;
            scanf("%d", &af);
            if(j == 0) continue;
            adj[bf].push_back(af);
            ind[af]++;
        }
    }

    solve();
}