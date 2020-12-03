#include <cstdio>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;
int clk[16];
int sw[10][16] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

void push(int clk[], int currSwitch) {
    for (int i = 0; i < 16; i++)
        clk[i] += sw[currSwitch][i];
}

int solve(int clk[], int currSwitch) {
    bool ok = true;
    for (int i = 0; i < 16; i++) {
        if (clk[i] % 4 != 0) ok = false;
    }
    if (currSwitch >= 10) return ok ? 0 : INF;
    int ret = INF;
    for (int cnt = 0; cnt < 4; cnt++) {
        ret = min(ret, cnt + solve(clk, currSwitch + 1));
        push(clk, currSwitch);
    }
    return ret;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int tmp;
        for (int i = 0; i < 16; i++) {
            scanf("%d", &tmp);
            clk[i] = (tmp/3)%4;
        }
        int ans = solve(clk, 0);
        printf("%d\n", ans == INF ? -1 : ans);
    }
    return 0;
}