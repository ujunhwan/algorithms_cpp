// 11057번 오르막 수
#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
int main()
{
    int n; scanf("%d", &n);
    int d[n+1][10];
    memset(d, 0, sizeof(d));
    int ans[n+1];
    memset(ans, 0, sizeof(ans));
    for(int i=0;i<=9;i++)
        d[1][i] = 1;
    ans[1] = 10;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int l=0;l<=j;l++)
            {
                d[i][j] += d[i-1][l];
                d[i][j] %= mod;
            }
        }
        for(int k=0;k<=9;k++)
        {
            ans[i] += d[i][k];
            ans[i] %= mod;
        }
    }
    printf("%d", ans[n]);
    return 0;
}