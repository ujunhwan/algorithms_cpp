// 1010번 다리 놓기
#include <cstdio>
long long dp[30][30];
int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        int n, m; scanf("%d %d", &n, &m);
        if (dp[n][m] > 0) {
            printf("%lld\n", dp[n][m]);
            continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                } else if (i == 1) {
                    dp[i][j] = j;
                    continue;
                }
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
        }
        printf("%lld\n", dp[n][m]);
    }
    return 0;
}