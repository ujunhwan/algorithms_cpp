// https://www.acmicpc.net/problem/1920
// 1920번 수 찾기

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

const int maxN = 100001;
const int maxM = 100001;

int N, M, a[maxN];

bool cmp(int a, int b) {
    return a < b;
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    cin >> M;

    sort(a, a+N, cmp);
    for(int num, i = 0; i < M; i++) {
        cin >> num;
        int lo = -1, hi = N;
        bool find = false;
        // (lo, hi]
        while(lo + 1 < hi) {
            int mid = (lo+hi)/2;
            // cout << lo << " " << mid << " " << hi << '\n';
            if(a[mid] < num) {
                lo = mid;
            } else if(a[mid] > num) {
                hi = mid;
            } else {
                hi = mid;
                break;
            }
        }
        if(a[hi] == num) puts("1");
        else puts("0");
    }
}

int main() {
    fastio;
    solve();
}