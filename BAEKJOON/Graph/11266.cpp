// https://www.acmicpc.net/problem/11266
// 11266번 단절점 

#include <bits/stdc++.h>
using namespace std;

int v, e, cnt, amt, visited[10001];
bool isCutVertex[10001];
vector<int> adj[10001];

int dfs(int here, bool isRoot) {
    bool cycle = false;
    visited[here] = ++cnt;
    int children = 0;
    int ret = visited[here];
    for(int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if(!visited[there]) {
            int sub = dfs(there, false);
            children++;
            if(!isRoot && sub >= visited[here])
                isCutVertex[here] = true;
            ret = min(ret, sub);
        }
        else ret = min(ret, visited[there]);
    }

    if(isRoot && children >= 2)
        isCutVertex[here] = true;

    return ret;
}

void solve() {
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < v; i++)
        if(!visited[i])
            dfs(i, true);
    
    vector<int> ans;
    
    for(int i = 0; i < v; i++)
        if(isCutVertex[i])
            ans.push_back(i);
    
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i] + 1);
}

int main() {
    scanf("%d %d", &v, &e);
    for(int p, q, i = 0; i < e; i++) {
        scanf("%d %d", &p, &q);
        p--, q--;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    solve();
}