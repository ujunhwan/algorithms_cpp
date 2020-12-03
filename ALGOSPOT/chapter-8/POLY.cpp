#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 10000000;
int cache[101][101];

int poly(int n, int taken) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == taken) return 1;
    int& ret = cache[n][taken];
    if(ret != -1) return ret;
    ret = 0;
    for(int contact = 1; contact + taken <= n; contact++) {
        ret = (ret + (taken + contact - 1) * poly(n - taken, contact)) % mod;
    }
    return ret % mod;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans + poly(n, i)) % mod;
        }
        cout << ans % mod << '\n';
    }
    return 0;
}