// https://www.acmicpc.net/problem/15666
// 15666번 N과 M (12) 

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, m, a[10], b[10], k;

void dfs(vector<int>&pick, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++)
            cout << pick[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = 0; i <= k; i++)
        if(cnt == 0 || pick[cnt-1] <= b[i]) {
            pick.push_back(b[i]);
            dfs(pick, cnt+1);
            pick.pop_back();
        }
}

void solve() {
    memset(b, 0, sizeof(b));
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    b[0] = a[0];
    k = 0;
    for(int i = 1; i < n; i++)
        if(b[k] < a[i])
            b[++k] = a[i];

    vector<int> pick;
    dfs(pick, 0);
}

int main() {
    fastio;
    solve();
}