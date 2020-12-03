#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int board[101][101];
int cache[101][101];

int path(int y, int x) {
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    if(y == n - 1) return ret = board[y][x];
    ret = max(path(y+1, x+1), path(y+1, x)) + board[y][x];
    return ret;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
                cin >> board[i][j];
        cout << path(0, 0) << '\n';
    }
    return 0;
}