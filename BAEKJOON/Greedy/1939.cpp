// https://www.acmicpc.net/problem/1939
// 1939번 중량제한

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct Edge {
    int a, b, c;
}; 

int N, M, src, dst;
Edge edges[100001];
int parent[10011];

int find(int u) {
    if(u < 0) return -1;
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    parent[u] = v;
}

bool cmp(Edge a, Edge b) {
    return a.c > b.c;
}

void solve() {
    cin >> N >> M;
    for(int a, b, c, i = 0; i < M; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }
    cin >> src >> dst;

    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int ans = 0;

    sort(edges, edges+M+1, cmp);

    for(auto edge : edges) {
        merge(edge.a, edge.b);
        if(find(src) == find(dst)) {
            ans = edge.c;
            break;
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}