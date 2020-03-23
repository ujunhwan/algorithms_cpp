// 13398번 연속합 2
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d", &n);
    int a[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    int d[n+1]; 
    int v[n+1]; 
    d[1] = a[1];
    for(int i=2;i<=n;i++)
    {
        d[i] = a[i];
        if(d[i] < d[i-1] || d[i-1] > 0)
            d[i] = d[i-1] + a[i];
    }
    v[n] = a[n];
    for(int i=n-1;i>=1;i--)
    {
        v[i] = a[i];
        if(v[i] < v[i+1] || v[i+1] > 0)
            v[i] = v[i+1] + a[i];
    }
    int ans = -1001;
    for(int i=1;i<=n;i++)
        ans = max(max(ans, d[i]), v[i]);
    for(int i=2;i<=n-1;i++)
        ans = max(ans, d[i-1] + v[i+1]);
    printf("%d\n",ans);
    return 0;

}