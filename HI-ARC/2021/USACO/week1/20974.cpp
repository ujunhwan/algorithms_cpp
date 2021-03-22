// https://www.acmicpc.net/problem/20974
// 20974번 Even More Odd Photos

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, even, odd;

void solve() {
    cin >> n;
    for(int id, i = 0; i < n; i++) {
        cin >> id;
        if(id&1) odd++;
        else even++;
    }

    int ans = 0;
    while(1) {
        // make even group
        if(even > 0) even--;
        else if(odd >= 2) odd -= 2;
        else break;
        ans++;

        // make odd group
        if(odd > 0) odd--;
        else break;
        ans++;
    }

    // more 2 odds left
    if(odd >= 1) ans--;
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}