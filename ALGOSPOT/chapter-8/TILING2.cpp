#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1000000007;
int cache[101];
int tiling(int n) {
    int& ret = cache[n];
    if(ret != -1) return ret;
    if(n == 0) return ret = 1;
    if(n == 1) return ret = 1;
    ret = (tiling(n - 1) + tiling(n - 2)) % mod;
    return ret;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(cache, -1, sizeof(cache));
        int n; cin >> n;
        cout << tiling(n) << '\n';
    }
    return 0;
}