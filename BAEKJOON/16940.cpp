// 16940번 BFS 스페셜 저지
#include <cstdio>
#include <queue>
using namespace std;
int n, u ,v, dist[100001], prv[100001], arr[100001];
queue<int> q;
vector<int> adj[100001];
bool vst[100001];
int phase[100001];
bool check (int x, int cur) {
    for (int i = 0; i < adj[cur].size(); i++) {
        int y = adj[cur][i];
        if (cur == y) continue;
        if (y == x) return true;
    }
    return false;
}
int go (int x) {
    int length, idx = 0;
    q.push(arr[idx++]); 
    while (idx < n) {
        int cur = q.front();
        q.pop();
        if (cur == arr[0]) length = adj[cur].size();
        else length = adj[cur].size() - 1;
        for (int i = 0; i < length; i++) {
            if(check(arr[idx], cur)) q.push(arr[idx++]);
            else return 0;
        }
    }
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if(arr[0] == 1) printf("%d\n", go(arr[0]));
    else puts("0");
    return 0;
}