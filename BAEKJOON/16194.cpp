// 16194번 카드 구매하기 2
#include <bits/stdc++.h>
using namespace std;
int ans[1001];
int P[1001];
int op(int n)
{
    if(n == 1) return P[n];
    if(ans[n] > 0) return ans[n];
    ans[n] = P[n];
    for(int i=1;i<n;i++)
        ans[n] = min(ans[n], P[i] + op(n-i));
    return ans[n];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(ans,-1,sizeof(ans));
    int N; cin >> N;
    for(int i=1;i<=N;i++) cin >> P[i];
    cout << op(N) << '\n';
}