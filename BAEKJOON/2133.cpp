// 2133번 타일 채우기
// d[0] = 1 을 하지 않아서 계속 틀렸다.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; scanf("%d", &n);
    if(n % 2 != 0)
    {
        printf("0\n");
        return 0;
    }
    long long d[n+1]; memset(d, 0, sizeof(d));
    d[0] = 1; d[2] = 3;
    for(int i=4;i<=n;i+=2)
    {
        d[i] = 3 * d[i-2];
        for(int j=4;j<=i;j+=2)
            d[i] += (2 * d[i-j]);
    }
    long long ans = d[n];
    printf("%lld\n", ans);
    return 0;
} 