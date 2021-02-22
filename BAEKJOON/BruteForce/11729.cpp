// https://www.acmicpc.net/problem/11729
// 11729번 하노이 탑 이동 순서

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

void dfs(int n, int from, int by, int to) {
    if(n == 1) {
        cout << from << " " << to << '\n';
        return;
    }
    dfs(n-1, from, to, by);
    cout << from << " " << to << '\n';
    dfs(n-1, by, from, to);
}

void solve() {
    int n; cin >> n;
    cout << (1<<n)-1 << '\n';
    dfs(n, 1, 2, 3);
}

int main() {
    fastio;
    solve();
}