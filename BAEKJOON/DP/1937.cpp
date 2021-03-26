// https://www.acmicpc.net/problem/1937
// 1937번 욕심쟁이 판다

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6);
using namespace std;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

int n, a[501][501], cache[501][501];

// y, x에서 시작해서 살아남은 최댓값
int dp(int y, int x) {
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 1;

    for(int k = 0; k < 4; k++) {
        int ny = y+d4y[k], nx = x+d4x[k];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if(a[ny][nx] > a[y][x])
            ret = max(ret, dp(ny, nx)+1);
    }

    return ret;
}

void solve() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    int ans = -1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, dp(i, j));

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}