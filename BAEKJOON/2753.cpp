// 2753번 윤년
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0)) puts("1");
    else puts("0");
    return 0;
}