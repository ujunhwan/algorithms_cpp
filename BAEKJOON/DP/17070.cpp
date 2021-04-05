// https://www.acmicpc.net/problem/17070
// 17070번 파이프 옮기기

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int n, a[22][22], dp[22][22][4];

bool checkWall(int y, int x, int state) {
    if(state == 1) {
        if(x >= 1 && y >= 1 && !a[y-1][x] && !a[y-1][x-1] && !a[y][x-1]) return true;
        return false;
    } else if(state == 2) {
        if(y >= 0 && x >= 1 && !a[y][x-1]) return true;
        return false;
    } else {
        if(y >= 1 && x >= 0 && !a[y-1][x]) return true;
        return false;
    }
    return false;
}

// \ 1, - 2, | 3
int dfs(int y, int x, int state) {
    if(a[y][x] == 1 || y < 0 || x < 0) return 0;
    if(y == 0 && x == 1) {
        if(state == 2 || state == 1) {
            return 1;
        }
        return 0;
    }
    if(x <= 1) return 0;

    int& ret = dp[y][x][state];
    if(ret != -1) return ret;
    ret = 0;
    if(checkWall(y, x, 1)) ret += dfs(y-1, x-1, 1);

    if(state == 1) {
        if(checkWall(y, x, 2))
            ret += dfs(y, x-1, 2);
        if(checkWall(y, x, 3))
            ret += dfs(y-1, x, 3);
    } else if(state == 2 && checkWall(y, x, 2)) ret += dfs(y, x-1, 2);
    else if(state == 3 && checkWall(y, x, 3)) ret += dfs(y-1, x, 3);

    return ret;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int k = 1; k <= 1; k++) {
        memset(dp, -1, sizeof(dp));
        ans += dfs(n-1, n-1, k);
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}