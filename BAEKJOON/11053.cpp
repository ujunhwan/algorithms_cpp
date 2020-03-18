// 11053번 가장 긴 증가하는 부분 수열
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int a[n], d[n], ans;
    for(int i=0;i<n;i++)
        cin >> a[i];
    ans = 1;
    for(int i=0;i<n;i++)
    {
        d[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(a[i] > a[j] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
        if(ans < d[i])
            ans = d[i];
    }
    cout << ans << '\n';
}
    