// https://www.acmicpc.net/problem/17836
// 17836번 공주님을 구해라!

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

int n, m, t, board[101][101], gram, dist[101][101];

void bfs() {
    int y, x;
    dist[0][0] = 0;
    queue<pii> q;
    q.emplace(0, 0);
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(board[ny][nx] != 1 && dist[ny][nx] == INF) {
                dist[ny][nx] = dist[y][x] + 1;
                q.emplace(ny, nx);
            }
        }
    }
}

void solve() {
    memset(board, -1, sizeof(board));
    memset(dist, 0x7f, sizeof(dist));
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) gram = i*m+j;
        }
    }

    bfs();

    int ans = min(dist[n-1][m-1], dist[gram/m][gram%m] + (n-1) - gram/m + (m-1) - gram%m);

    if(ans > t) puts("Fail");
    else cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}