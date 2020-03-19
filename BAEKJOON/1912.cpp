// 1912번 연속합
#include <bits/stdc++.h>
using namespace std;
int a[100001], d[100001], v[1000001];
int main()
{
    int n; cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i]; 
    int ans = a[0];
    d[0] = a[0];   
    v[0] = 0;
    for(int i=1;i<n;i++)
    {
        d[i] = d[i-1] + a[i];
        v[i] = v[i-1] + 1;
        if(d[i] < a[i])
        {
            d[i] = a[i];
            v[i] = 0;
        }
        ans = max(ans, d[i]);
    }
    cout << ans << '\n';
}