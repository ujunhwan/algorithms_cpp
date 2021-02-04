// https://www.acmicpc.net/problem/11066
// 11066번 파일 합치기

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 987654321;
int tc, k, dp[501][501], sum[501];

int main() {
    for(scanf("%d", &tc); tc--;) {
        scanf("%d", &k);

        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));

        for(int s, i = 0; i < k; i++) {
            scanf("%d", &s);
            if(i == 0) {
                sum[i] = s;
                continue;
            }
            sum[i] = sum[i-1] + s;
        }
        
        // range
        for(int r = 1; r < k; r++)
            // start
            for(int s = 0; s + r < k; s++) {
                // end
                int e = s + r;
                int psum = sum[e] - sum[s-1];
                dp[s][e] = INF;
                for(int k = s; k < e; k++)
                    dp[s][e] = min(dp[s][e], dp[s][k] + dp[k+1][e] + psum);
            }
        
        printf("%d\n", dp[0][k-1]);
    }
}