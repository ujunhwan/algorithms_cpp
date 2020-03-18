// 1330번 두 수 비교하기
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b; cin >> a >> b;
    string ans;
    if(a > b) ans += '>';
    else if(a < b) ans += '<';
    else ans += "==";
    cout << ans << '\n';
}