// 2438번 별 찍기 - 1
#include <bits/stdc++.h>
int main()
{
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}