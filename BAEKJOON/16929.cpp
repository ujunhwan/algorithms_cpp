// 16929번 Two Dots
#include <cstdio>
#include <stack>
using namespace std;
int n, m;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
char dot[50][50];
int chk[50][50];
inline bool dfs(int x, int y) {
    stack<pair<int, int> >s;
    int ix = x, iy = y;
    printf("\n");
    printf("ix : %d iy : %d\n", ix, iy);
    int cnt = 0;
    s.push(make_pair(x, y));
    chk[x][y] = 1;
    while(!s.empty()) {
        x = s.top().first;
        y = s.top().second;
        printf("%c %d %d %d\n",dot[x][y], x, y, chk[x][y]);
        s.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            printf("nx : %d ny : %d\n", nx, ny);
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (dot[nx][ny] == dot[x][y] && chk[nx][ny] > 0 && (chk[x][y] - chk[nx][ny]) >= 3) {
                    printf("TRUE\n");
                    return true;
                }
                if (chk[nx][ny] == 0 && dot[nx][ny] == dot[x][y]) {
                    s.push(make_pair(x, y));
                    s.push(make_pair(nx, ny));
                    chk[nx][ny] = chk[x][y] + 1;
                    break;
                }
            }
        }
    }
    return false;
}
int main() {
    scanf("%d %d", &n, &m); getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1c", &dot[i][j]);
        }
        getchar();
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (chk[i][j] == 0)
                if(dfs(i, j)) {
                    puts("Yes");
                    return 0;
                }
        }
    }
    puts("No");
    return 0;
}