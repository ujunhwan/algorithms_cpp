// 9465번 스티커
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        int a[n+1][2], d[n+1][3]; // 0 nothing 1 up 2 down
        for(int i=1;i<=n;i++)
            scanf("%d", &a[i][0]);
        for(int i=1;i<=n;i++)
            scanf("%d", &a[i][1]);
        d[1][0] = 0; d[1][1] = a[1][0]; d[1][2] = a[1][1];
        for(int i=2;i<=n;i++)
        {
            d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
            d[i][1] = max(d[i-1][0], d[i-1][2]) + a[i][0];
            d[i][2] = max(d[i-1][0], d[i-1][1]) + a[i][1];
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
            ans = max(ans, max(d[i][0], max(d[i][1], d[i][2])));
        printf("%d\n",ans);
    }
    return 0;
}
