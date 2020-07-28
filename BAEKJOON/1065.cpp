// 1065번 한수
#include <iostream>
using namespace std;
int main () {
    int n; cin >> n;
    if (n == 1000) {
        cout << "144" << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i < 10) ans += 1;
        else if (i >= 10 && i < 100) ans += 1;
        else {
            int hundreds = i / 100;
            int tens = (i % 100) / 10;
            int units = i % 10;
            int d1 = hundreds - tens, d2 = tens - units;
            if (d1 == d2) ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}