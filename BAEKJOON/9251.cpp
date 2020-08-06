// 9251번 LCS
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001], ans, len1, len2;
string str1, str2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str1 >> str2;
    len1 = str1.length(); len2 = str2.length(); // table 생각해서 풀음 너무어려웠어~~
    for(int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if (str1[i] == str2[j]) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                if (i == 0 && j == 0) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = dp[i][j-1];
                else if (j == 0) dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
    }
    ans = dp[len1-1][len2-1];
    cout << ans << '\n';
    return 0;
}