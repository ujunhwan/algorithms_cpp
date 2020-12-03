#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long k;
long long bino[201][201];
const long long INF = 1000000000 + 100;

string morse(int n, int m) {
    string ret = "";
    if(n == 0) {
        return string(m, 'o');
    }
    long long comp = bino[n + m - 1][n - 1];
    if(k > comp) {
        k -= comp;
        return 'o' + morse(n, m - 1);
    } else {
        return '-' + morse(n - 1, m);
    }
}

string kth(int n, int m, int skip) {
    if(n == 0) return string(m, 'o');
    if(skip >= bino[n + m - 1][n - 1])
        return 'o' + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
    return '-' + kth(n - 1, m, skip);
}

void precalc() {
    memset(bino, 0, sizeof(bino));
    for(int i = 0; i <= 200; i++) {
        bino[i][0] = 1;
        bino[i][i] = 1;
        for(int j = 1; j < i; j++)
            bino[i][j] = min(INF, bino[i-1][j-1] + bino[i-1][j]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    precalc();
    while(tc--) {
        int n, m; cin >> n >> m >> k;
        cout << morse(n, m) << '\n';
        int skip = k;
        cout << kth(n, m, skip) << '\n';
    }
    return 0;
}