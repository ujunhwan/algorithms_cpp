#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

int C, N;
int largest;
double x[51], y[51], r[51];

void init() {
    for(int i = 0; i < 51; i++)
        x[i] = y[i]= r[i] = 0;
}

double dist(int p1, int p2) {
    double ret = pow(x[p1] - x[p2], 2) + pow(y[p1] - y[p2], 2);
    return sqrt(ret);
}

int solve() {
    int ret = 0;
    queue<int> q;
    for(int i = 0; i < N; i++) {
        vector<int> cand;
        double d = dist(largest, i);
        if(d < (r[largest] + r[i])) {
            
        }
    }

    return ret;
}

int main() {
    cout << fixed;
    cout.precision(8);
    fio; cin >> C;
    while(C--) {
        init();
        cin >> N;
        
        int tmp = 0;
        for(int i = 0; i < N; i++) {
            cin >> y[i] >> x[i] >> r[i];
            if(tmp < r[i])
                largest = i;
        }
        cout << solve() << '\n';
    }
    return 0;
}