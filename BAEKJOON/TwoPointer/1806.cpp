// https://www.acmicpc.net/problem/1806
// 1806번 부분합

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, S;
vector<int> seq;

void solve() {
    cin >> N >> S;
    seq = vector<int> (N+1, 0);
    for(int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    int start = 0, end = 0;
    int ans = INF;

    ll psum = seq[0];

    while(start <= end && end <= N-1 && psum >= 0) {
        if(end == N-1 && psum < S) break;
        if(psum < S) {
            psum += seq[++end];
        } else {
            ans = min(ans, end-start+1);
            psum -= seq[start++];
        }
    }
    
    cout << (ans == INF ? 0 : ans) << '\n';
}

int main() {
    fastio;
    solve();
}