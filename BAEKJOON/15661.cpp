// 15661번 스타트와 링크
#include <cstdio>
int n, s[20][20], a[20], b[20], an, bn;
int go(int index) {
    if(an > n / 2 || bn > n / 2) return -1;
    if(index == n && an > 0 && bn > 0) {
        int s1 = 0;
        for (int i = 0; i < an; i ++) {
            for (int j = i + 1; j < an; j ++) {
                s1 += s[a[i]][a[j]] + s[a[j]][a[i]];
            }
        }
        for (int i = 0; i < bn; i ++) {
            for (int j = i + 1; j < bn; j ++) {
                s1 -= s[b[i]][b[j]] + s[b[j]][b[i]];
            }
        }
        return s1 > 0 ? s1 : -s1;
    }
    if(index >= n) return -1;
    int ans = 1 << 30;
    a[an++] = index;
    int t1 = go(index + 1);
    if (t1 < ans && t1 > -1) ans = t1;
    an -= 1;
    b[bn++] = index;
    int t2 = go(index + 1);
    if (t2 < ans && t2 > -1) ans = t2;
    bn -= 1;
    return ans;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) 
    for (int j = 0; j < n; j ++)
        scanf("%d", &s[i][j]);
    printf("%d\n", go(0));
    return 0;
}