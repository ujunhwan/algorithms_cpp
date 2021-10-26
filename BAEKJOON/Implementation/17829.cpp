// https://www.acmicpc.net/problem/17829
// 17829번 222-풀링

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static const int INF = 0x7f7f7f7f;

int N, a[1025][1025];

bool cmp(int a, int b) {
    return a > b;
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    int size = N;
    while(size > 1) {
        for(int i = 0; i < size; i+=2) {
            for(int j = 0; j < size; j+=2) {
                int lu = a[i][j];
                int ld = a[i][j+1];
                int ru = a[i+1][j];
                int rd = a[i+1][j+1];
                vector<int> b = {lu, ld, ru ,rd};
                sort(b.begin(), b.end(), cmp);
                a[i/2][j/2] = b[1];
            }
        }

        size /= 2;
    }

    int ans = a[0][0];
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}

/*

*/