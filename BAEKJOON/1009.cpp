// 1009번 분산처리
#include <cstdio>
int n, a, b;
static inline int go (int x, int y) {
    int ret = 1;
    while (y--) {
        ret *= x;
        ret = (ret - 1) % 10 + 1;
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        b = (b - 1) % 4 + 1;
        printf("%d\n", go(a, b));
    } 
    return 0;
}