// https://www.acmicpc.net/problem/a
// a번 

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

const int maxN = 100;

int N, a[maxN+1], X, Y;

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    cin >> X >> Y;
    int ansX = N*X/100, ansY = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] >= Y) ansY++;
    }

    cout << ansX << " " << ansY << '\n';
}

signed main() {
    fastio;
    solve();
}