// https://www.acmicpc.net/problem/1944
// 1944번 복제 로봇

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct Edge {
    int w, u, v;
    Edge(int w, int u, int v) : w(w), u(u), v(v) {}
};

const int INF = 987654321;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, parent[2501], vn;
char maze[51][51];
bool isVertex[2501];
bool isPossible;

vector<Edge> edges;

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    parent[u] = v;
}

bool cmp(const Edge&a, const Edge&b) {
    return a.w < b.w;
}

int bfs(int from) {
    int arr[51][51], ret = 1;
    memset(arr, -1, sizeof(arr));
    arr[from / n][from % n] = 0;

    queue<int> q;
    q.push(from);

    while(!q.empty()) {
        int here = q.front();
        int x = here % n, y = here / n;
        int cost = arr[y][x];
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int there = n * ny + nx;
            if(nx < 0 || ny < 0 || nx > n || ny > n) continue;
            if(maze[ny][nx] == '1' || arr[ny][nx] != -1) continue;
            arr[ny][nx] = cost + 1;
            q.push(there);
            if(isVertex[there]) {
                edges.push_back(Edge(arr[ny][nx], from, there));
                ret++;
            }
        }

        if(ret == m + 1)
            return ret;
    }

    return ret;
}

void solve() {
    for(int i = 0; i < n * n + 1; i++) {
        if(!isVertex[i]) continue;
        if(bfs(i) == m + 1) continue;
        puts("-1");
        return;
    }

    sort(edges.begin(), edges.end(), cmp);

    for(int i = 0; i < n * n + 1; i++)
        parent[i] = i;

    int ans = 0;

    for(int i = 0; i < edges.size(); i++) {
        int w = edges[i].w;
        int u = edges[i].u;
        int v = edges[i].v;
        if(find(u) == find(v)) continue;
        merge(u, v);
        ans += w;
    }

    printf("%d\n", ans);
}

int main() {
    vn = 0;
    isPossible = true;
    memset(isVertex, false, sizeof(isVertex));

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", maze[i]);
        for(int j = 0; j < n; j++) {
            if(maze[i][j] == '1' || maze[i][j] == '0') continue;
            int here = n * i + j;
            isVertex[here] = true;
        }
    }

    solve();
}