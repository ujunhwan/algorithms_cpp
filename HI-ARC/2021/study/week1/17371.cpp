// https://www.acmicpc.net/problem/17371
// 17371번 이사 

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6);
using namespace std;

typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int n;

inline int dist(pii a, pii b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

void solve() {
    cin >> n;
    vector<pii> a(n);
    for(pii& el : a) cin >> el.first >> el.second;

    // idx, dist
    pii ans = make_pair(-1, INF);

    for(int i = 0; i < a.size(); i++) {
        int maxIdx, maxDist = -1;
        for(int j = 0; j < a.size(); j++) {
            int nowDist = dist(a[i], a[j]);
            if(nowDist > maxDist) {
                maxIdx = i;
                maxDist = nowDist;
            }
        }
        
        if(ans.second > maxDist) {
            ans.first = maxIdx;
            ans.second = maxDist;
        }
    }

    cout << a[ans.first].first << " " << a[ans.first].second << '\n';
}

int main() {
    fastio;
    decimal;
    solve();
}