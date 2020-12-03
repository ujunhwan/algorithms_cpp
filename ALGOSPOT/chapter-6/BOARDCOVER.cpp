#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

int h, w;
int board[21][21];
bool checked[21][21];

const int coverType [4][3][2] = {
    { {0, 0}, {1, 0}, {1, -1} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {0, 1}, {1, 0} },
    { {0, 0}, {1, 0}, {1, 1} }
};

bool set(int y, int x, int type, int delta) {
    bool ret = true;
    for (int i = 0; i < 3; i ++) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (ny < 0 || ny >= h || nx < 0 || ny >= w) ret = false;
        else if ((board[ny][nx] += delta) > 1) ret = false;
    }
    return ret;
}

int cover() {
    int y = -1, x = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 0) {
                y = i, x = j;
                goto EXIT;
            }
        }
    }
    EXIT:
    if (x == -1 || y == -1) return 1;
    int ret = 0;
    for (int type = 0; type < 4; type++) {
        if (set(y, x, type, 1)) ret += cover();
        set(y, x, type, -1);
    }
    return ret;
}

int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        memset(board, 0, sizeof(board));
        memset(checked, false, sizeof(checked));
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char tmp; scanf(" %c", &tmp);
                if (tmp == '#') {
                    board[i][j]= 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
        printf("%d\n", cover());
    }
    return 0;
}
/*
1
3 7
#.....# 
#.....# 
##...##
*/