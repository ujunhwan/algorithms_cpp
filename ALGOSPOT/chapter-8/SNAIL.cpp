#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
double cache[1001][1001];

double climb(int days, int climbed) {
    double&ret = cache[days][climbed];
    if(ret != -1) return ret;
    if(days == m) return climbed >= n ? 1 : 0;
    ret = 0.75 * climb(days + 1, climbed + 2) + 0.25 * climb(days + 1, climbed + 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(10);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        for(int i = 0; i < 1001; i++) {
            for(int j = 0; j < 1001; j++) {
                cache[i][j] = -1;
            }
        }
        cout << climb(0, 0) << '\n';
    }
    return 0;
}