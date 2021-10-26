// https://www.acmicpc.net/problem/10816
// 10816번 숫자 카드 2

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

const int maxN = 500000;
int N, a[maxN+10], M;

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    cin >> M;
    sort(a, a+N);
    
    for(int i = 0; i < M; i++) {
        int K; cin >> K;
        int lo = -1, hi = N-1;
        while(lo + 1 < hi) {
            int mid = (lo+hi)/2;
            if(a[mid] < K) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        int lower = hi;
        if(a[lower] != K) {
            cout << "0" << " ";
            continue;
        }
        lo = hi, hi = N;
        while(lo + 1 < hi) {
            int mid = (lo+hi)/2;
            if(a[mid] <= K) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        int upper = lo;
        int ans = upper - lower + 1;
        cout << ans << " ";
    }
    cout << '\n';
}

int main() {
    fastio;
    solve();
}

/*
10
6 -5 -5 10 10 10 -10 -10 -10 3
6
-10 -5 2 3 6 10

5
1 1 1 1 1
1
5

5
1 1 1 1 1
1
1

6
1 2 2 2 3 4
1
2

10
-10 -2 -2 -2 3 4 4 4 4 10
6
-2 3 4 1 5 10

*/