// 2004번 조합 0의 개수
#include <iostream>
using namespace std;
typedef long long ll;
ll numOfX(ll n, ll x)
{
    ll cnt = 0;
    for(ll i=1;i<=n;i*=x)
        cnt += n / i;
    return cnt;
}

int main()
{
    ll n,m; cin >> n >> m;
    int two = numOfX(n,2) - numOfX(m,2) - numOfX(n-m,2);
    int five = numOfX(n,5) - numOfX(m,5) - numOfX(n-m,5);
    cout << min(two,five);
    return 0;
}