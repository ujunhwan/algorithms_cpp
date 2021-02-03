// https://www.acmicpc.net/problem/2839
// 2839번 설탕 봉지

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, dp[5001];

int main() {
    scanf("%d", &n);
    fill(dp, dp + n + 1, INF);
    dp[3] = dp[5] = 1;
    for(int i = 6; i <= n; i++)
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
    
    printf("%d\n", dp[n] >= INF ? -1 : dp[n]);
}