// 1932번 정수 삼각형
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d", &n);
    int a[n+1][n+1];
    int d[n+1][n+1];
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d", &a[i][j]);
    d[1][1] = a[1][1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            d[i][j] = max(d[i-1][j], d[i-1][j-1]) + a[i][j];
    int ans = 0;
    for(int k=1;k<=n;k++)
        ans = max(ans, d[n][k]);
    printf("%d\n", ans);
    return 0;
}