// 14002번  가장 긴 증가하는 부분 수열 4
// 초기값 때문에 많이 틀림
#include <bits/stdc++.h>
using namespace std;
int a[1001],d[1001],v[1001];
void op(int n)
{
    if(n <= 0) return;
    op(v[n]);
    cout << a[n] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i=1;i<=n;i++) 
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        d[i] = 1;
        v[i] = 0;
        for(int j=1;j<i;j++)
            if(a[i] > a[j] && d[i] < d[j] + 1)
            {
                d[i] = d[j] + 1;
                v[i] = j;
            }
    }
    int ans = d[0];
    int p = 0;
    for(int i=1;i<=n;i++)
    {
        if(ans < d[i])
        {
            ans = d[i];
            p = i;
        }
    }
    cout << ans << '\n';
    op(p);
    cout << '\n';
}
