// https://www.acmicpc.net/problem/22957
// 22957번 짝수싫어수

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

ll N, K;
ll dp[33][10];

// 1 -> odd, 0 -> even
void solve() {
    memset(dp, 0, sizeof(dp));
    char mapp[3] = {'3', '5', '7'};
    cin >> N >> K;

    for(int i = 0; i <= 7; i++) {
        bool isZero = false;
        for(int j = 0; j <= 2; j++) {
            if((i^(1<<j)) == 0) {
                isZero = true;
            }
        }
        if(isZero) dp[1][i] = 2;
        else dp[1][i] = 3;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 7; j++) {
            for(int k = 0; k <= 2; k++) {
                dp[i][j] += dp[i-1][j^(1<<k)];
            }
        }
    }

    int state = 0;

    vector<char> ans;
    for(int i = N; i >= 1; i--) {
        for(int j = 2; j >= 0; j--) {
            // if((state^(1<<j)) == 0) continue;
            if(dp[i-1][state^(1<<j)] < K) {
                K -= dp[i-1][state^(1<<j)];
                continue;
            } else {
                ans.push_back(mapp[j]);
                state ^= (1<<j);
                break;
            }
        }
    }

    for(auto b : ans) {
        cout << b;
    }

    // K번째 !
    if(K != 0) {
        int num = -1;
        for(int j = 2; j >= 0; j--) {
            if((state^(1<<j)) == 0) num = j;
        }

        // K = 1 -> 7, K = 2 -> 5, K = 3 -> 3

        // num = 2 면 K = 1 -> 5, K = 2 -> 3 K=1부터 ++
        // num = 1 이면 K = 1 -> 7, K = 2 -> 3 K=2부터 ++
        // num = 0 이면 K = 1 -> 7, K = 2 -> 5 K=3부터 ++ 

        if(num == 2) {
            K++;
        } else if(num == 1) {
            if(K == 2) K++;
        }

        cout << mapp[3-K];
    }
}

int main() {
    fastio;
    solve();
}

/*
1 1
7

1 2
5

1 3
3

2 1
75

2 2
73

2 3
57
*/