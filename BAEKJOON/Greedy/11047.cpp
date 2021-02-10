#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int INF = 0x7f7f7f7f;
int n, k, a[11];

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] <= k) {
            int times = k / a[i];
            ans += times;
            k -= times * a[i];
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}