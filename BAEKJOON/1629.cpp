// 1629번 곱셈
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull go (ull a, ull b, ull c) {  // a^b 를 반환
    if (b == 1) return a;
    bool odd = false;
    ull tmp = b;
    if (b % 2 == 0) {
        tmp /= 2;
    } else {
        tmp = (tmp - 1) / 2;
        odd = true;
    }
    ull ret = go (a, tmp, c);
    if (odd) {
        ret = (((ret % c) * (ret % c) % c) * (a % c)) % c;
    } else {
        ret = ((ret % c) * (ret % c)) % c;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ull a, b, c, ans;
    cin >> a >> b >> c;
    if (b == 1) {
        ans = a % c;
    } else {
        ans = go(a, b, c);
    }
    cout << ans << '\n';
    return 0;
}