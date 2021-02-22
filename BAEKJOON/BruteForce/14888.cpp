// https://www.acmicpc.net/problem/14888
// 14888번 연산자 끼워넣기

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int INF = 987654321*2;

vector<int> oper, a;
int maxv, minv, n;

// + - * /

void dfs(int currIndex, int currValue) {
    if(currIndex == n) {
        maxv = max(maxv, currValue);
        minv = min(minv, currValue);
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(oper[i] <= 0) continue;
        if(i == 0) {
            oper[i]--;
            dfs(currIndex+1, currValue+a[currIndex]);
            oper[i]++;
        }
        else if(i == 1) {
            oper[i]--;
            dfs(currIndex+1, currValue-a[currIndex]);
            oper[i]++;
        }
        else if(i == 2) {
            oper[i]--;
            dfs(currIndex+1, currValue*a[currIndex]);
            oper[i]++;
        }
        else {
            oper[i]--;
            dfs(currIndex+1, currValue/a[currIndex]);
            oper[i]++;
        }
    }
}

void solve() {
    cin >> n;
    a = vector<int>(n);
    oper = vector<int>(4);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];

    maxv = -INF, minv = INF;
    dfs(1, a[0]);

    cout << maxv << '\n' << minv << '\n';
}

int main() {
    fastio;
    solve();
}