// 7562번 나이트의 이동
#include <cstdio>
#include <queue>
using namespace std;
typedef struct pos {
    int x, y;
} Pos;
const int lth = 300;
int tc, n, mp[lth][lth], ans;
int dx[] = {-2, -1, -2, -1, 1, 2, 1, 2}, dy[] = {1, 2, -1, -2, -2, -1, 2, 1};
Pos init, gl;
int bfs(Pos init) {
    queue<Pos> q;
    q.push(init);
    mp[init.x][init.y] = 1;
    while (!q.empty()) {
        Pos cur = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            Pos nxt;
            nxt.x = cur.x + dx[i];
            nxt.y = cur.y + dy[i];
            if (nxt.x >= 0 && nxt.y >= 0 && nxt.x < n && nxt.y < n) {
                if (nxt.x == gl.x && nxt.y == gl.y) 
                    return mp[cur.x][cur.y];
                else if (mp[nxt.x][nxt.y] == 0) {
                    q.push(nxt);
                    mp[nxt.x][nxt.y] = mp[cur.x][cur.y] + 1;
                }
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d\n", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mp[i][j] = 0;
        scanf("%d %d", &init.x, &init.y);
        scanf("%d %d", &gl.x, &gl.y);
        if(init.x == gl.x && init.y == gl.y) ans = 0;
        else ans = bfs(init);
        printf("%d\n", ans);
    }
    return 0;
}