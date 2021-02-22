// https://www.acmicpc.net/problem/1931
// 1931번 회의실 배정

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

int n;

bool cmp(pii a, pii b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void solve() {
    vector<pii> conf;
    cin >> n;
    for(int s, e, i = 0; i < n; i++) {
        cin >> s >> e;
        conf.push_back(make_pair(s, e));
    }

    sort(conf.begin(), conf.end(), cmp);
    
    int end = 0, ans = 0;
    for(int i = 0; i < conf.size(); i++) {
        if(end <= conf[i].first) {
            ans++;
            end = conf[i].second;
        }
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}