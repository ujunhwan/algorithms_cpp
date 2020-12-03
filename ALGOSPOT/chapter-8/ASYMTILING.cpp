#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
int cache[101];

int tiling(int n) {
    int& ret = cache[n];
    if(ret != -1) return ret;
    if(n == 0) return 1;
    if(n == 1) return 1;
    ret = (tiling(n -1) + tiling(n - 2)) % mod;
    return ret;
}

int asymmetric(int n) {
    if(n % 2 == 1) return tiling(n / 2) % mod;
    int ret = tiling(n);
    ret = (ret - tiling(n / 2) + mod) % mod;
    n -= 2;
    ret = (ret - tiling(n / 2) + mod) % mod;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        cout << asymmetric(n) << '\n';
    }
    return 0;
}