// https://www.acmicpc.net/problem/11051
// 11051번 이항 계수 2

#include <bits/stdc++.h>
using namespace std;

int n, k, bino[1001][1001];
const int MOD = 10007;

int main() {
    scanf("%d %d", &n, &k);

    memset(bino, 0, sizeof(bino));

    for(int i = 0; i <= n; i++) {
        bino[i][i] = bino[i][0] = 1;
        bino[i][1] = i;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            bino[i][j] = (bino[i-1][j-1] + bino[i-1][j]) % MOD;
    
    printf("%d\n", bino[n][k]);
}