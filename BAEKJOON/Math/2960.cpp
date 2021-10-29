// https://www.acmicpc.net/problem/2960
// 2960번 에라노스테네스의 체

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

const int maxN = 1000;
int N, K;
bool isPrime[maxN+1];

void solve() {
    memset(isPrime, true, sizeof(isPrime));
    cin >> N >> K;
    int cnt = 0;
    for(int i = 2; i <= N; i++) {
        if(isPrime[i]) {
            cnt++;
            if(cnt == K) {
                cout << i << '\n';
                return;
            }
            for(int j = i*2; j <= N; j+=i) {
                if(isPrime[j] == true) {
                    cnt++;
                }
                isPrime[j] = false;
                if(cnt == K) {
                    cout << j << '\n';
                    return;
                }
            }
        }
    }
}

int32_t main() {
    fastio;
    solve();
}