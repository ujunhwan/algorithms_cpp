// https://www.acmicpc.net/problem/17827
// 17827번 달팽이 리스트

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, M, V, c[200001];

void solve() {
    cin >> N >> M >> V;
    for(int i = 1; i <= N; i++) cin >> c[i];
    int cycle = N-V+1;
    int b = N-cycle;
    vector<int> cand;
    for(int i = 0; i < M; i++) {
        int K; cin >> K;
        int val;
        if(K < N) val = K+1;
        else val = ((K-b)%cycle)+V;
        cand.push_back(val);
    }

    for(auto idx : cand) {
        int ans = c[idx];
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}

/*
10 10 3
13 2 5 11 7 8 2 4 9 10
1
2
3
8
9
10
11
16
17
49

10 10 3
13 2 5 11 7 8 2 4 9 10
1
2
3
10
18
24
25
26
27
28

idx : 2 3 4 3 3 9 10 3 4 5

5 10 4
1 2 3 4 5
1
2
3
4
5
6
7
8
9
10

*/
