// 2293번 동전 1
#include <bits/stdc++.h>
using namespace std;
long long value[10001], dp[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) 
        cin >> value[i];
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j - value[i] >= 0) {
                dp[j] += dp[j - value[i]];
            }
        }
    }
    long long ans = dp[k];
    cout << ans << '\n';
    return 0;
}