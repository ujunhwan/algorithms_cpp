// https://www.acmicpc.net/problem/20972
// 20972번 Spaced Out

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, a[1001][1001];
int col[1001][2], row[1001][2];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j+=2) row[i][0] += a[i][j];
        for(int j = 1; j < n; j+=2) row[i][1] += a[i][j];
        for(int j = 0; j < n; j+=2) col[i][0] += a[j][i];
        for(int j = 1; j < n; j+=2) col[i][1] += a[j][i];
    }

    int cand1 = 0;
    for(int i = 0; i < n; i++) cand1 += max(row[i][0], row[i][1]);

    int cand2 = 0;
    for(int i = 0; i < n; i++) cand2 += max(col[i][0], col[i][1]);

    int ans = max(cand1, cand2);
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}