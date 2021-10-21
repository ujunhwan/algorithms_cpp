// https://www.acmicpc.net/problem/13392
// 13392번 방법을 출력하지 않는 숫자 맞추기

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f+1;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N;
vector<int> curr, rslt;

int cache[10011][11];

int dp(int idx, int already) {
    if(idx == N) return 0;
    int& ret = cache[idx][already];
    if(ret != 0x7f7f7f7f) return ret;
    ret = INF;
    
    int curValue = (curr[idx] + already) % 10;
    int lcnt = (rslt[idx] - curValue + 10) % 10;
    int rcnt = (curValue - rslt[idx] + 10) % 10;

    int left = dp(idx+1, (already+lcnt) % 10) + lcnt;
    int right = dp(idx+1, already) + rcnt;

    return ret = min(left, right);
}

void solve() {
    memset(cache, 0x7f, sizeof(cache));
    cin >> N;
    curr = vector<int> (N+1);
    rslt = vector<int> (N+1);

    string str;
    cin >> str;
    for(int i = 0; i < N; i++) {
        curr[i] = str[i] - '0';
    }

    cin >> str;
    for(int i = 0; i < N; i++) {
        rslt[i] = str[i] - '0';
    }

    int ans = dp(0, 0);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}