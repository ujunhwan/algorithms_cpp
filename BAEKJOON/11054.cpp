// 11054번 가장 긴 바이토닉 부분 수열
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d", &n);
    int a[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int d[n+1]; // n에서 끝나는 가장 긴 수열의 길이 (증가)
    int v[n+1]; // n에서 시작하는 가장 긴 수열의 길이 (감소)
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int k = n-i+1;
        d[i] = 1;
        v[k] = 1;
        for(int j=1;j<i;j++)
        {
            if(a[i] > a[j] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
        for(int l=n;l>k;l--)
        {
            if(a[k] > a[l] && v[k] < v[l] + 1)
                v[k] = v[l] + 1;
        }
    }
    for(int i=1;i<=n;i++)
        ans = max(ans,d[i] + v[i]);
    ans -= 1;
    printf("%d\n", ans);
    return 0;
}
    