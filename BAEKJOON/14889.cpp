// 14889번 스타트와 링크
#include <bits/stdc++.h>
using namespace std;
int s[20][20];
int go(int n, int index, vector <int> &a, vector <int> &b) {
    if (a.size() > n/2 || b.size() > n/2) return -1;
    if (index == n) {
        int diff = 0;
        for (int i = 0; i < n / 2; i ++) {
            for (int j = i + 1; j < n / 2; j ++) {
                diff += s[a[i]][a[j]] + s[a[j]][a[i]];
                diff -= s[b[i]][b[j]] + s[b[j]][b[i]];
            }
        }      
        return diff > 0 ? diff : -diff;
    }
    a.push_back(index);
    int ans = 1 << 30;
    int d1 = go(n, index + 1, a, b);
    if(d1 < ans && d1 > -1) {
        ans = d1;
    }
    a.pop_back();
    b.push_back(index);
    int d2 = go(n, index + 1, a, b);
    if(d2 < ans && d2 > -1) {
        ans = d2;
    }
    b.pop_back();
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    vector <int> a, b;
    cout << go(n, 0, a, b) << '\n';
    return 0;
}