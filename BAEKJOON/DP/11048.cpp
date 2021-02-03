// https://www.acmicpc.net/problem/11048
// 11048번 이동하기

#include <bits/stdc++.h>
using namespace std;

int n, m, candy[1001][1001], dp[1001][1001];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &candy[i][j]);
    
    dp[0][0] = candy[0][0];
    for(int i = 1; i < n; i++)
        dp[i][0] = candy[i][0] + dp[i-1][0];

    for(int i = 1; i < m; i++)
        dp[0][i] = candy[0][i] + dp[0][i-1];

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1])) + candy[i][j];
    
    printf("%d\n", dp[n-1][m-1]);
}