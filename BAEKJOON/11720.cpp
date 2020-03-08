// 11720번 숫자의 합
#include <stdio.h>
int main()
{
    int N; scanf("%d",&N);
    int num,ans = 0;
    while(N--)
    {
        scanf("%1d",&num);
        ans += num;
    }
    printf("%d",ans);
}