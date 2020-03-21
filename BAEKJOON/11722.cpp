// 11722번 가장 긴 감소하는 부분 수열
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d", &n);
    vector <int> a(n+1);
    vector <int> d(n+1);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(int i=1;i<=n;i++)
    {
        d[i] = 1;
        for(int j=1;j<i;j++)
            if(a[i] < a[j] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
    }
    int ans = *max_element(d.begin(), d.end());
    printf("%d\n", ans);
    return 0;
}