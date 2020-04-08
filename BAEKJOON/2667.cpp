// 2667번 단지번호붙이기
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int mapArr[25][25], check[25][25], n;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
int bfs(int x, int y, int cnt) {
    queue <pair<int, int> > q;
    int ret = 0;
    q.push(make_pair(x, y));
    check[x][y] = cnt; ret++;
    while (!q.empty()) {
        x = q.front().first; y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (check[nx][ny] == 0 && mapArr[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = cnt; ret++;
                }
            }
        }
    }
    return ret;
}
int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) 
        scanf("%1d", &mapArr[i][j]);
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++)
        if (mapArr[i][j] > 0 && check[i][j] == 0) {
            ans.push_back(bfs(i, j, ++cnt));
        }
    printf("%d\n", cnt);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < cnt; i++) 
        printf("%d\n", ans[i]);
    return 0;
}