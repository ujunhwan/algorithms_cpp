// https://www.acmicpc.net/problem/2178
// 2178번 미로 탐색 

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

int n, m, dist[101][101], y, x;
string maze[101];
queue<pii> q;

void solve() {
    memset(dist, 0x7f, sizeof(dist));
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> maze[i];
    q.emplace(y, x);
    dist[y][x] = 1;
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(maze[ny][nx] == '1' && dist[ny][nx] > dist[y][x]+1) {
                dist[ny][nx] = dist[y][x]+1;
                q.emplace(ny, nx);
            }
        }
    }

    int ans = dist[n-1][m-1];
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}