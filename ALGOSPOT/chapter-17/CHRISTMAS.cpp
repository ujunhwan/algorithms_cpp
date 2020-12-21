#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

static const int MOD = 20091101;
static const int INF = 987654321;
int T, N, K, Di[100000 + 2];
int psum[100000 + 2];
long long modCount[100000 + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    while(T--) {
        memset(psum, 0, sizeof(psum));
        memset(modCount, 0, sizeof(modCount));

        cin >> N >> K;
        for(int i = 1; i <= N; i++)
            cin >> Di[i];

        int ans1 = 0;
        psum[0] = 0;
        for(int i = 1; i <= N; i++)
            psum[i] = (psum[i - 1] + Di[i]) % K;

        for(int i = 0; i <= N; i++)
            modCount[psum[i]]++;

        for(int i = 0; i < K; i++)
            if(modCount[i] >= 2)
                ans1 = (ans1 + (modCount[i] * (modCount[i] - 1) / 2)) % MOD;

        int ans2[100000 + 2];
        int prev[100000 + 2];

        memset(ans2, 0, sizeof(ans2));
        memset(prev, -1, sizeof(prev));

        for(int i = 0; i <= N; i++) {
            if(i > 0) ans2[i] = ans2[i - 1];
            else ans2[i] = 0;

            int loc = prev[psum[i]];
            if(loc != -1) ans2[i] = max(ans2[i], ans2[loc] + 1);
            prev[psum[i]] = i;
        }

        cout << ans1 << " " << ans2[N] << '\n';
    }
    return 0;
}
