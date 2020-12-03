#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int solve(bool isFriend[][10], bool checked[], int MAX) {
    int firstFree = -1;
    for (int i = 0; i < MAX; i++) {
        if (!checked[i]) {
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1) return 1;
    for (int i = 0; i < MAX; i++) {
        if (isFriend[i][firstFree]) {
            checked[i] = checked[firstFree] = true;
        }
    }


}

int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        bool isFriend[10][10] = { 0 };
        bool checked[10] = { 0 };
        int n,m; scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            int t1, t2; scanf("%d %d", &t1, &t2);
            isFriend[t1][t2] = true;
            isFriend[t2][t1] = true;
        }
        int ans = solve(0, 0, isFriend, checked, n);
        printf("%d\n", ans);
    }
    return 0;
}
/*
1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
*/
