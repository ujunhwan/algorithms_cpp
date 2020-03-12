// 2745번 진법 변환
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string N; int B; cin >> N >> B;
    reverse(N.begin(),N.end());
    ll ans = 0; int cnt = 0;
    for(char ch : N)
    {
        int num;
        if(ch >= 65 && ch <= 90) ch -= 55;
        else ch -= '0';
        num = ch;
        ans += num * pow(B,cnt++);
    }
    cout << ans;
}