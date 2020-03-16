// 15990번 1, 2, 3 더하기 5
#include <bits/stdc++.h>
#define MOD 1000000009
using namespace std;
typedef long long ll;
ll ans[100001][4];
ll op(int n, int front) 
{
    if(n < 0) return 0;
    if(ans[n][front] > 0) return ans[n][front];
    if(n == 0)
    {
        ans[n][front]= 1;
        return ans[n][front];
    }
    if(n <= 2 && n == front) 
    {
        ans[n][front] = 0;
        return ans[n][front];
    }
    if(front == 1)
        ans[n][front] = (op(n-2, 2) + op(n-3, 3)) % MOD;
    if(front == 2)
        ans[n][front] = (op(n-1, 1) + op(n-3, 3)) % MOD;
    if(front == 3) 
        ans[n][front] = (op(n-2,2) + op(n-1,1)) % MOD;
    return ans[n][front];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(ans,-1,sizeof(ans));
    int T; cin >> T; 
    while(T--)   
    {
        int n; cin >> n; 
        cout << (op(n-1, 1) + op(n-2, 2) + op(n-3, 3)) % MOD<< '\n';
    }
}
