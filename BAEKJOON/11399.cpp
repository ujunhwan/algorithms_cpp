// 11399번 ATM
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p+n);
    int ans = p[0];
    for (int i = 1; i < n; i++) {
        p[i] += p[i-1];
        ans += p[i];
    }
    cout << ans << '\n';
    return 0;
}