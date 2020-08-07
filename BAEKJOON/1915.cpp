// 1915번 가장 큰 정사각형
#include <bits/stdc++.h>
using namespace std;
char arr[1001][1001];
int dp[1001][1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool flag = false;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == '0') dp[i][j] = -1;
            else if (i == 0 || j == 0) {
                flag = true;
                dp[i][j] = 0;
            }
            else {
                flag = true;
                int left = dp[i][j-1];
                int right = dp[i-1][j];
                int diag = dp[i-1][j-1];
                if (left == -1 || right == -1 || diag == -1) dp[i][j] = 0;
                else {
                    dp[i][j] = min(left, min(right, diag)) + 1;
                    ans = max(dp[i][j] , ans);
                }
            }
        }
    }
    if (flag && (n == 1 || m == 1)) {
        cout << "1" << '\n';
    } else if (flag){
        ans = (ans + 1) * (ans + 1);
        cout << ans << '\n';
    } else {
        cout << "0" << '\n';
    }
    return 0;
}