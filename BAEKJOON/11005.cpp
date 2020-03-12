// 11005번 진법 변환 2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll N; int B; cin >> N >> B;
    string ans;
    while(N != 0)
    {
        int num = N % B;
        if(num > 9)
        {
            num += 55;
            ans += num;
        }
        else ans += to_string(num);
        N = N / B;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}