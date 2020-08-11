// 1520번 내리막 길
#include <bits/stdc++.h>
using namespace std;
int ans, arr[501][501], dp[501][501];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int go(int i, int j, int n, int m) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int ni = i + dy[k], nj = j + dx[k];
        if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
        if (arr[ni][nj] > arr[i][j])
            dp[i][j] += go(ni, nj, n, m);
    }
    return dp[i][j];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    int ans = go(n-1, m-1, n, m);
    cout << ans << '\n';
    return 0;
}