// https://www.acmicpc.net/problem/14267
// 14267번 회사 문화 1

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, m, sup[100011], comp[100011]; 

void solve() {
    memset(comp, 0, sizeof(comp));
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> sup[i];
    for(int num, w, i = 0; i < m; i++) {
        cin >> num >> w;
        comp[num] += w;
    }

    for(int i = 1; i <= n; i++) {
        if(i == 1) cout << comp[1] << " ";
        else {
            comp[i] += comp[sup[i]];
            cout << comp[i] << " ";
        }
    }
}

int main() {
    fastio;
    solve();
}