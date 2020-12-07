#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int C, N, K, M, L;
int pre[13], subject[11];
int Ri[13], Ci[11];

int calc() {
    int ret = 0;
    int taken = 0;
    for(int semester = 0; semester < M; semester++) {
        int limit = L;
        int currentTaken = taken;
        bool take = false;
        for(int i = 0; i < Ci[semester]; i++) {
            if(limit == 0) continue;
            if(currentTaken & (1 << i)) continue;
            // 이번학기 열리고, 안들었고, 선수과목이 없거나 들었으면 수강
            if((subject[semester] & (1 << i)) && (pre[i] == 0 || (currentTaken & pre[i]) == pre[i])) {
                take = true;
                taken |= (1 << i);
                limit--;
            }
        }
        if(take) ret++;
        if(__builtin_popcount(taken) == K) return ret;
    }
    return 1000;
}

int main() {
    fio; cin >> C;
    while(C--) {
        memset(pre, 0, sizeof(pre));
        memset(subject, 0, sizeof(subject));
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
        int ans = calc();
        if(ans > 10) cout << "IMPOSSIBLE" << '\n';
        else cout << ans << '\n';
    }
    return 0;
}
