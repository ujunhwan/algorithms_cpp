// https://www.acmicpc.net/problem/11000
// 11000번 강의실 배정

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

// start, end
priority_queue<pii, vector<pii>, greater<pii> > classq;
priority_queue<int, vector<int>, greater<int> > roomq;
int n, s, e;

void solve() {
    cin >> n;
    for(int a, b, i = 0; i < n; i++) {
        cin >> a >> b;
        classq.emplace(a, b);
    }

    int ans = 0;
    while(!classq.empty()) {
        tie(s, e) = classq.top();
        classq.pop();

        if(roomq.empty()) {
            roomq.push(e);
            ans++;
        } else {
            int minEnd = roomq.top();
            if(s >= minEnd) roomq.pop();
            else ans++;
            roomq.push(e);
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}

/*
3
1 4
2 3
3 4

ans : 2


3
1 3
2 4
3 5

ans : 2

4
1 3
2 4
3 5
3 5

ans : 3
*/