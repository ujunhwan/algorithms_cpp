#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 1000000007;
int c, n, m;
int cache[1 << 14][20][2];
string digits, e;

void precalc(void) {
    memset(cache, -1, sizeof(cache));
    digits = e;
    sort(digits.begin(), digits.end());
    n = digits.size();
}

int price(int index, int taken, int mod, int less) {
    if(index == n) return (less && mod == 0) ? 1 : 0;
    int& ret = cache[taken][mod][less];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = 0; next < n; next++) {
        if((taken & (1 << next)) == 0) {
            if(less == 0 && e[index] < digits[next]) continue;
            if(next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0) continue;
            int nextTaken = taken | (1 << next);
            int nextMod = (mod * 10 + digits[next] - '0') % m;
            int nextLess = less || e[index] > digits[next];
            ret += price(index + 1, nextTaken, nextMod, nextLess);
            ret %= MOD;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> c;
    while(c--) {
        cin >> e >> m;
        precalc();
        cout << price(0, 0, 0, 0) << '\n';
    }
    return 0;
}
