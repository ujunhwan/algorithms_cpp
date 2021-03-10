// https://www.acmicpc.net/problem/1987
// 1987번 알파벳

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
int r, c;
string a[21];

int dfs(int trace, int y, int x, int cnt) {
    int ret = 0;
    int here = a[y][x] - 'A';
    if(trace & (1 << here)) return cnt;
    trace |= (1 << here);
    for(int k = 0; k < 4; k++) {
        int ny = y + d4y[k], nx = x + d4x[k];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        ret = max(ret, dfs(trace, ny, nx, cnt + 1));
    }
    return ret;
}

void solve() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) cin >> a[i];

    cout << dfs(0, 0, 0, 0) << '\n';
}

int main() {
    fastio;
    solve();
}