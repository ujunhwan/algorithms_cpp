#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int friends[10][10];
int countPairing(bool taken[10], int n) {
    int first = -1;
    for (int i = 0; i < n; ++i) {
        if(taken[i] == false) {
            first = i;
            break;
        }
    }
    if (first == -1) return 1;
    int ret = 0;
    for (int i = first+1; i < n; ++i) {
        if (taken[i] == false && friends[first][i] == true) {
            taken[first] = taken[i] = true;     // 이 부분 중요하다!!!!!!!!!!!
            ret += countPairing(taken, n);
            taken[first] = taken[i] = false;
        }
    }
    return ret;
}
int main() {
    int tc; cin >> tc;
    while (tc--) {
        bool taken[10];
        fill(taken, taken + 10, 0);
        fill(&friends[0][0], &friends[9][10], false);
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int first, second; cin >> first >> second;
            friends[first][second] = true;
            friends[second][first] = true;
        }
        int ans = countPairing(taken, n);
        cout << ans << '\n';
    }
}