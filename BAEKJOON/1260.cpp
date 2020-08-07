// 1260번 DFS와 BFS
#include <bits/stdc++.h>
using namespace std;
vector <int> adj[1001];
int vstDFS[1001];
int vstBFS[1001];
stack <int> s;
queue <int> q;
void dfs (int x) {
    int cur, nxt;
    int cnt = 0;
    s.push(x);
    vstDFS[x] = 1;
    cout << x << " ";   // 이것도 원래는 없었음 틀렸던 코드와 비교!!
    while(!s.empty()) {
        cur = s.top(); s.pop();
        // cout << cur << " ";
        int length = adj[cur].size();
        sort(adj[cur].begin(), adj[cur].end());
        for (int i = 0; i < length; i++) {
            nxt = adj[cur][i];
            if (vstDFS[nxt] == 0) {
                s.push(cur);
                s.push(nxt);
                cout << nxt << " "; // 스택에 넣고, 다음 노드를 출력해야 중복이 안됨
                vstDFS[nxt] = 1;
                break;
            }
        }
    }
}
void bfs (int x) {
    int cur, nxt;
    int cnt = 0;
    q.push(x);
    vstBFS[x] = 1;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        cout << cur << " ";
        int length = adj[cur].size();
        for (int i = 0; i < length; i++) {
            nxt = adj[cur][i];
            if (vstBFS[nxt] == 0) {
                vstBFS[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, v; cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(v);
    cout << '\n';
    bfs(v);
    return 0;
}
// 원래코드는 스택이 팝 되면서 중복이 발생하였다 이것을 방지하기 위해서
// 카운트를 하는등의 기법을 사용해봤지만 소용 X 방문노드를 출력하는 위치를 바꾸어서 해결함 
// 중복을 방지하기 위해, 현재의 노드를 스택에 푸시하지않을 수 있지만, 그렇게 한다면 처음으로 돌아가지 못한다 따라서 잘못된 방법