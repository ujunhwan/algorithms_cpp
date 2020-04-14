// 1261번 알고스팟
#include <cstdio>
#include <deque>
using namespace std;
int n, m, x, y, mze[100][100], dist[100][100];
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
deque<pair<int, int> >dq;
void bfs() {
    dq.push_back(make_pair(0, 0));
    dist[0][0] = 1;
    while (!dq.empty()) {
        x = dq.front().first; y = dq.front().second;
        dq.pop_front();
        if (x == n-1 && y == m-1) {
            printf("%d\n", dist[x][y] - 1);
            return;
        }
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (dist[nx][ny] == 0 && mze[nx][ny] == 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back(make_pair(nx, ny));
                }
                else if (dist[nx][ny] == 0 && mze[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y];
                    dq.push_front(make_pair(nx, ny));
                }
            }
        }
    }
}
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &mze[i][j]);
        }
    }
    bfs();
    return 0;
}