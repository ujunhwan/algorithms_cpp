// 2163번 초콜릿 자르기
#include <cstdio>
int main () {
    int n, m; scanf("%d %d", &n, &m);
    long long ans = n - 1 + n * (m - 1);
    printf("%lld\n", ans);
    return 0;
}