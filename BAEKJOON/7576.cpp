// 7576번 토마토
#include <cstdio>
#include <queue>
using namespace std;
const int lth = 1000;
int n, m, dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0}, tmt[lth][lth], ck[lth][lth];
queue<pair<int, int> >q;
void bfs() {
    int x, y, mDay = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (tmt[nx][ny] == 0 && ck[nx][ny] == 0) {
                    ck[nx][ny] = ck[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
int main() {
    scanf("%d %d\n", &n, &m); // n=6 m=4
    for (int i = 0; i < m; i++) 
    for (int j = 0; j < n; j++) {
        scanf("%d", &tmt[i][j]);
        if (tmt[i][j] == 1) {
            q.push(make_pair(i, j));
            ck[i][j] = 1;
        }
    }
    bfs();
    int ans = 0;
    bool all = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ans < ck[i][j]) ans = ck[i][j];
            if (ck[i][j] == 0 && tmt[i][j] == 0) all = false;
        }
    }
    all ? printf("%d\n", ans - 1) : puts("-1");
    return 0;
}