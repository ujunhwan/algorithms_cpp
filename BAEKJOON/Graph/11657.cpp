// https://www.acmicpc.net/problem/11657
// 11657번 타임머신
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e+18;
const ll M = 9876532;
int n, m;
vector<pair<int, ll> > adj[501];

vector<ll> spfa(int src) { 
    vector<ll> dst(n, INF);
    vector<bool> inQ(n, false);
    vector<int> cnt(n, 0);

    dst[src] = 0;
    queue<ll> q;
    q.push(src);
    inQ[src] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inQ[u] = false;

        for(int i = 0; i < adj[u].size(); i++) {
            int cst = adj[u][i].second;
            int v = adj[u][i].first;

            if(dst[v] > dst[u] + cst) {
                dst[v] = dst[u] + cst;

                if(!inQ[v]) {
                    q.push(v);
                    inQ[v] = true;
                    cnt[v]++;

                    if(cnt[v] >= n) {
                        puts("-1");
                        exit(0);
                    }
                }
            }
        }
    }
    dst.erase(dst.begin());
    return dst;
}

void solve() {
    vector<ll> ans = spfa(0);
    for(int i = 0; i < ans.size(); i++)
        printf("%lld\n", ans[i] >= INF - M ? -1 : ans[i]);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        ll a, b, w;
        scanf("%lld %lld %lld", &a, &b, &w);
        adj[a-1].push_back(make_pair(b-1, w));
    }

    solve();
}