// 1476번 날짜 계산
#include <cstdio>
int main()
{
    int E, S, M; scanf("%d %d %d", &E, &S, &M);
    int ans = 1;
    while(1){
        if((ans - 1) % 15 + 1 == E && (ans - 1) % 28 + 1 == S && (ans - 1) % 19 + 1 == M)
            break;
        ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}