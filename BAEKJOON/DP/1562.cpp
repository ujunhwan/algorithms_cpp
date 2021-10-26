// https://www.acmicpc.net/problem/1562
// 1562번 계단 수

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

const ll MOD = 1000000000;

int N;

ll cache[101][11][1025];

ll dfs(int digit, int num, int vst) {
    if(digit > N) return 0;
    if(digit == N) {
        if(vst == 1023) return 1;
        else return 0;
    }
    ll& ret = cache[digit][num][vst];
    if(ret != -1) return ret;
    ret = 0;
    if(num < 9) {
        ret += dfs(digit+1, num+1, vst|(1<<(num+1))) % MOD;
        ret %= MOD;
    }
    if(num > 0) {
        ret += dfs(digit+1, num-1, vst|(1<<(num-1))) % MOD;
        ret %= MOD;
    }
    return ret;
}

void solve() {
    memset(cache, -1, sizeof(cache));
    cin >> N;
    ll ans = 0;
    for(int i = 1; i <= 9; i++) {
        ans = (ans % MOD + dfs(1, i, (1<<i)) % MOD) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}