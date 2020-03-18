// 2193번 이친수
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    long long ans[N];
    ans[0] = 0; ans[1] = 1;
    for(int i = 2;i<=N;i++)
        ans[i] = ans[i-1] + ans[i-2];
    cout << ans[N] << '\n';
}