// 11055번 가장 큰 증가 부분 수열
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d", &n);
    int a[n+1], d[n+1];
    int ans = 0;
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<=n;i++)
    {
        d[i] = a[i];
        for(int j=1;j<i;j++)
        {
            if(a[i] > a[j] && d[i] < d[j] + a[i])
                d[i] = d[j] + a[i];
        }
        ans = max(ans, d[i]);
    }
    printf("%d\n", ans);
}