// https://www.acmicpc.net/problem/2662
// 2662번 기업투자

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, M, prf[333][22];
int cache[333][22];
int seq[333][22];

// dp(left, cpny) = 남은 돈 left원, cpny번 회사 차례일 때 최대 이익
int dp(int left, int cpny) {
    if(cpny > M) return 0;
    if(left < 0) return 0;
    int& ret = cache[left][cpny];
    if(ret != -1) return ret;
    ret = 0;

    for(int invst = 0; invst <= left; invst++) {
        int cand = dp(left-invst, cpny+1)+prf[invst][cpny];
        if(ret < cand) {
            ret = cand;
            seq[left][cpny] = invst;
        }
    }

    return ret;
}

void reconstruct(int left, int cpny) {
    if(cpny > M) return;
    cout << seq[left][cpny] << " ";
    reconstruct(left-seq[left][cpny], cpny+1);
}

void solve() {
    memset(cache, -1, sizeof(cache));
    memset(prf, 0, sizeof(prf));
    memset(seq, 0, sizeof(seq));
    cin >> N >> M;
    for(int c, i = 0; i < N; i++) {
        cin >> c;
        for(int a, j = 1; j <= M; j++) {
            cin >> a;
            // c를 j회사에 투자하면 얻는 이익
            prf[c][j] = a;
        }
    }

    int ans = dp(N, 1);
    cout << ans << '\n';

    reconstruct(N, 1);
}

int main() {
    fastio;
    solve();
}