// 10844번 쉬운 계단 수
#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;
typedef long long ll;
ll arr[101][10];
ll op(int length, int last)
{
    if(length <= 0 || last < 0 || last > 9) return 0;
    if(arr[length][last] >= 0) return arr[length][last];
    if(length == 1)
    {
        if(last == 0)
        {
            arr[length][last] = 0;
            return arr[length][last];
        }
        arr[length][last] = 1;
        return arr[length][last];
    }
    arr[length][last] = (op(length - 1, last + 1) + op(length - 1, last - 1)) % MOD;
    return arr[length][last];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(arr,-1,sizeof(arr));
    int N; cin >> N;
    ll ans = 0;
    for(int i=0;i<=9;i++)
        ans = (ans + op(N,i)) % MOD;
    cout << ans % MOD << '\n';
}