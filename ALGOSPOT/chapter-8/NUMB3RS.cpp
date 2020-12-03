#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int A[51][51], edge[51];
int n, d, p, t, q;
double cache[51][101];   // 번호, day

double probability(int num, int day) {
    double&ret = cache[num][day];
    if(ret != -1) return ret;
    if(day == 1) return A[num][p] == 1 ? ret = (1 / (double)edge[p]) : 0;
    ret = 0;
    for(int i = 0; i < n; i++)
        if(A[i][num] == 1)
            ret += (1 / (double)edge[i]) * probability(i, day - 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        memset(edge, 0, sizeof(edge));
        for(int y = 0; y < 51; y++)
            for(int x = 0; x < 101; x++)
                cache[y][x] = -1;

        vector<double> ans;
        cin >> n >> d >> p;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> A[i][j];
                if(A[i][j] > 0) edge[i] += 1;
            }
        }
        cin >> t;
        for(int k = 0; k < t; k++) {
            cin >> q;
            cout << fixed << setprecision(8) << probability(q, d) << '\n';
        }
    }
    return 0;
}