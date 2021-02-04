// https://www.acmicpc.net/problem/11049
// 11049번 행렬 곱셈 순서

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 987654321;
int n;
vector<pii> matrix;
ll dp[501][501];

int main() {
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for(int r, c, i = 0; i < n; i++) {
        scanf("%d %d", &r, &c);
        matrix.push_back(make_pair(r, c));
    }

    for(int r = 1; r < n; r++) {
        for(int s = 0; r + s < n; s++) {
            int e = r + s;
            dp[s][e] = INF;
            for(int k = s; k < e; k++) {
                int calc = matrix[s].first * matrix[k+1].first * matrix[e].second;
                dp[s][e] = min(dp[s][e], dp[s][k] + dp[k+1][e] + calc);
            }
        }
    }

    printf("%lld\n", dp[0][n-1]);
}