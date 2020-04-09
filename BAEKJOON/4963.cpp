// 4963번 섬의 개수
#include <cstdio>
#include <queue>
using namespace std;
int w, h, ans, mp[50][50], ck[50][50];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
void bfs(int x, int y) {
    queue<pair<int, int> >q;
    q.push(make_pair(x, y));
    ck[x][y] = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
                if (ck[nx][ny] == 0 && mp[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    ck[nx][ny] = 1;
                }
            }
        }
    }
}
int main() {
    while(1) {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                mp[i][j] = 0, ck[i][j] = 0;
                scanf("%d", &mp[i][j]);
            }
        }
        ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(mp[i][j] == 1 && ck[i][j] == 0) {
                    bfs(i, j); 
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}