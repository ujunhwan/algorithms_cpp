// 9613번 GCD 합
// long long 안해서 틀렸음
#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    if(b == 0)
        return a;
    return GCD(b,a%b);
}
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int num[n];
        ll ans = 0;
        for(int i=0;i<n;i++)
            cin >> num[i];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                ans += GCD(num[i],num[j]);
        }
        cout << ans << '\n';
    }
    return 0;
}