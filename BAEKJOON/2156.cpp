// 2156번 포도주 시식
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d", &n);
    long long a[n+1], d[n+1][2];
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    d[0][0] = d[0][1] = 0;
    d[1][0] = 0; d[1][1] = a[1];
    for(int i=2;i<=n;i++)
    {
        d[i][1] = max(d[i-1][0], d[i-2][0] + a[i-1]) + a[i];
        d[i][0] = max(d[i-1][0], d[i-1][1]);
    }
    long long ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(max(ans, d[i][0]), d[i][1]);
    printf("%lld\n", ans);
    return 0;
}