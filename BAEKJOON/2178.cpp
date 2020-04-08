// 2178번 미로 탐색
#include <cstdio>
#include <queue>
using namespace std;
int n, m, x, y, mze[100][100], visited[100][100], dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
queue<pair<int, int> >q;
int main() {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++)   
    for (int j = 0; j < m; j++)
        scanf("%1d", &mze[i][j]);
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    while (!q.empty()) {
        x = q.front().first; y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (visited[nx][ny] == 0 && mze[nx][ny] == 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    printf("%d\n", visited[n-1][m-1]);
    return 0;
}