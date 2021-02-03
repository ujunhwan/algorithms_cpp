// https://www.acmicpc.net/problem/15486
// 15486번 퇴사 2

#include <bits/stdc++.h>
using namespace std;

int n, dp[100];

int main() {
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    scanf("%d", &n);
    for(int t, p, i = 0; i < n; i++) {
        ans = max(ans, dp[i%51]);
        scanf("%d %d", &t, &p);
        dp[(i+1)%51] = max(dp[(i+1)%51], dp[i%51]);
        dp[(i+t)%51] = max(dp[(i+t)%51], dp[i%51] + p);
    }

    ans = max(ans, dp[n%51]);

    printf("%d\n", ans);
}