#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int INF = -987654321;
int N, W;
int x[1002], y[1002];
int cache[1001][1001];

inline int dist(int d1, int d2) {
    return abs(d2 / 10000 - d1 / 10000) + abs(d2 % 10000 - d1 % 10000);
}

int entrust(int a, int b) {
    if(a == W || b == W) return 0;
    int&ret = cache[a][b];
    if(ret != -1) return ret;

    int index = max(a, b) + 1;

    int p1 = y[a] * 10000 + x[a];
    int p2 = (b != 0) ? y[b] * 10000 + x[b] : N * 10000 + N;
    int event = y[index] * 10000 + x[index];
    
    int cand1 = entrust(index, b) + dist(p1, event);
    int cand2 = entrust(a, index) + dist(p2, event);
    ret = min(cand1, cand2);
    return ret;
}

void reconstruct(int a, int b) {
    if(a == W || b == W) return;
    int index = max(a, b) + 1;

    int p1 = y[a] * 10000 + x[a];
    int p2 = (b != 0) ? y[b] * 10000 + x[b] : N * 10000 + N;
    int event = y[index] * 10000 + x[index];

    int dist1 = entrust(index, b) + dist(p1, event);
    int dist2 = entrust(a, index) + dist(p2, event);
    if(dist1 > dist2) {
        cout << "2" << '\n';
        reconstruct(a, index);
    } else {
        cout << "1" << '\n';
        reconstruct(index, b);
    }
}

int main() {
    fio; cin >> N >> W;
    y[0] = 1, x[0] = 1;
    for(int i = 1; i <= W; i++)
        cin >> y[i] >> x[i];
    memset(cache, -1, sizeof(cache));
    cout << entrust(0, 0) << '\n';
    reconstruct(0, 0);
    return 0;
}