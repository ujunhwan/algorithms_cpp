// https://www.acmicpc.net/problem/14003
// 14003번 가장 긴 증가하는 부분 수열 5

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int n, a[1000001], b[1000001], x[1000001], len;

void solve() {
    memset(a, 0x7f, sizeof(a));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        int pos = lower_bound(a+1, a+n+1, x[i]) - a;
        a[pos] = x[i];
        if(pos > len) len++;
        b[i] = pos;
    }

    int pos = len;
    for(int i = n; i >= 1; i--) {
        if(b[i] != pos) {
            b[i] = 0;
            continue;
        }
        pos--;
    }

    cout << len << '\n';
    for(int i = 1; i <= n; i++)
        if(b[i]) cout << x[i] << " ";
}

int main() {
    fastio;
    solve();
}