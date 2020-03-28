// 14501번 퇴사
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void go (int index,int sum, int n, int *t, int *p) {
    if (index == n) {
        if(ans < sum) ans = sum;
        return;
    }
    if (index > n) return;
    go(index + t[index], sum + p[index], n, t, p);
    go(index + 1, sum, n, t, p);
}
int main() {
    int n; cin >> n;
    int t[16], p[16];
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    go(1, 0, n + 1, t, p);
    cout << ans << '\n';
    return 0;
}