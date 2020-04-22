// 9461번 파도반 수열
#include <cstdio>
int n, tc;
long long p[101] = {1, 1, 1, };
int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        if (p[n-1] > 0) {
            printf("%lld\n", p[n-1]);
            continue;
        }
        for (int i = 3; i < n; i++) {
            p[i] = p[i-2] + p[i-3];
        }
        printf("%lld\n", p[n-1]);
    }
    return 0;
}