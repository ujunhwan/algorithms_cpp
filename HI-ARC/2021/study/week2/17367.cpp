// https://www.acmicpc.net/problem/17367
// 17367번 공교육 도박

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(12)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

double dp[11][11][1111];

inline double reward(string str) {
    sort(str.begin(), str.end());
    string origin = str;
    str.erase(unique(str.begin(), str.end()), str.end());
    char ch = str[str.size()-1];
    if(str.size() == 1) return 10000 + (ch - '0') * 1000;
    else if(str.size() == 2) {
        if(origin[2] == origin[1]) return 1000 + (ch - '0') * 100;
        else return 1000 + (origin[1] - '0') * 100;
    }
    else return (ch - '0') * 100;
    return 0;
}

double dfs(int second, int first, int left) {
    if(left == 0) return 0;
    double& ret = dp[second][first][left];
    if(ret != 0) return ret;

    string state = to_string(second) + to_string(first);

    for(int i = 1; i <= 6; i++)
        ret += max(reward(state + to_string(i)), dfs(first, i, left-1));
    ret /= 6;

    return ret;
}

void solve() {
    memset(dp, 0, sizeof(dp));
    int n; cin >> n;
    double ans = 0;
    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= 6; j++) {
            ans += dfs(i, j, n-2);
        }
    }
    ans /= 36;

    cout << ans << '\n';
}

int main() {
    fastio;
    decimal;
    solve();
}