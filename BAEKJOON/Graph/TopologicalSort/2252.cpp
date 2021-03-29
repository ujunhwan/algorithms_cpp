// https://www.acmicpc.net/problem/2252
// 2252번 줄 세우기

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int n, m, ind[32001];
vector<int> adj[32001];

void solve() {
    cin >> n >> m;
    for(int p, q, i = 0; i < m; i++) {
        cin >> p >> q;
        adj[p].push_back(q);
        ind[q]++;
    }

    vector<int> ans;

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(ind[i] == 0) q.push(i);
    
    for(int i = 1; i <= n; i++) {
        if(q.empty()) break;

        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        for(int el : adj[curr])
            if(--ind[el] == 0) q.push(el);
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}

int main() {
    fastio;
    solve();
}