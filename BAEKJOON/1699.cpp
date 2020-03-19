// 1699번 제곱수의 합
#include <bits/stdc++.h>
using namespace std;
int ans[100001];
int go(int n)
{
    if(n <= 0) return 0;
    if(ans[n] >= 0) return ans[n];
    int sqrtN = sqrt(n);
    int d = sqrtN * sqrtN;
    if(d == n)
    {
        ans[n] = 1;
        return ans[n];
    }
    ans[n] = go(n-1) + go(1);
    for(int i=2;i<=sqrtN;i++)
    {
        int tmp = ans[n];
        ans[n] = go(n-i*i) + go(i*i);
        if(ans[n] > tmp)
            ans[n] = tmp;
    }
    return ans[n];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(ans, -1, sizeof(ans));
    int n; cin >> n;
    ans[n] = go(n);
    cout << ans[n] << '\n';
    return 0;
}
