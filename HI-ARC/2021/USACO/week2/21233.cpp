// https://www.acmicpc.net/problem/21233
// 21233번 Year of the Cow

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;

int n, k;

void solve() {
    cin >> n >> k;
    vector<ll> a;
    for(int s, i = 0; i < n; i++) {
        cin >> s;
        a.push_back((s/12+1)*12);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll ans = a[a.size()-1];
    k--;

    priority_queue<ll> pq;

    int end = 0;
    for(int i = 0; i < a.size()-1; i++) {
        int start = a[i]-12;
        pq.push(start - end);
        end = a[i];
    }

    while(!pq.empty()) {
        if(k == 0) break;
        int dist = pq.top();
        pq.pop();

        ans -= dist;
        k--;
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}