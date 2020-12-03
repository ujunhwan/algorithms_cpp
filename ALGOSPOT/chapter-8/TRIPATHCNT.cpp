#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int board[101][101];
int pcache[101][101], ccache[101][101];

int path(int y, int x) {
    int& ret = pcache[y][x];
    if(ret != -1) return ret;
    if(y == n - 1) return ret = board[y][x];
    ret = max(path(y+1, x+1), path(y+1, x)) + board[y][x];
    return ret;
}

int count(int y, int x) {
    int& ret = ccache[y][x];
    if(ret != -1) return ret;
    if(y == n - 1) return 1;
    if(pcache[y+1][x] > pcache[y+1][x+1]) {
        ret = count(y+1, x);
    } else if(pcache[y+1][x] < pcache[y+1][x+1]) {
        ret = count(y+1, x+1);
    } else {
        ret = count(y+1, x) + count(y+1, x+1);
    }
    return ret;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(pcache, -1, sizeof(pcache));
        memset(ccache, -1, sizeof(ccache));
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= i; j++)
                cin >> board[i][j];
        path(0, 0);
        cout << count(0, 0) << '\n';
    }
    return 0;
}