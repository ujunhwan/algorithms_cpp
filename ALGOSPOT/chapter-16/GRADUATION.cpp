#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

const int INF = 987654321;
int C, N, K, M, L;
int pre[13], subject[11];
int Ri[13], Ci[11];
int cache[10 + 1][1 << 12 + 1];

int calc(int semester, int taken) {
    if(__builtin_popcount(taken) >= K) return 0;
    if(semester  == M) return INF;

    int&ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;

    int canTake = (subject[semester] & ~taken);

    for(int i = 0; i < N; i++)
        if(canTake & (1 << i) && (taken & pre[i]) != pre[i])
            canTake &= ~(1 << i);

    for(int take = canTake; take > 0; take = (take - 1) & canTake) {
        if(__builtin_popcount(take) > L) continue;
        ret = min(ret, calc(semester + 1, taken | take) + 1);
    }

    ret = min(ret, calc(semester + 1, taken));
    return ret;
}

int main() {
    fio; cin >> C;
    vector<int> ans;
    while(C--) {
        memset(pre, 0, sizeof(pre));
        memset(subject, 0, sizeof(subject));
        memset(cache, -1, sizeof(cache));
        cin >> N >> K >> M >> L;
        int num;
        for(int i = 0; i < N; i++) {
            cin >> Ri[i];
            for(int j = 0; j < Ri[i]; j++) {
                cin >> num;
                pre[i] |= (1 << num);
            }
        }
        for(int i = 0; i < M; i++) {
            cin >> Ci[i];
            for(int j = 0; j < Ci[i]; j++) {
                cin >> num;
                subject[i] |= (1 << num);
            }
        }
        ans.push_back(calc(0, 0));
    }

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] > 10) cout << "IMPOSSIBLE" << '\n';
        else cout << ans[i] << '\n';
    }

    return 0;
}