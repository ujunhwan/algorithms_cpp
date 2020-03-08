// 2443번 별 찍기 - 6
#include <bits/stdc++.h>
int main()
{
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i-1;j++)
            printf(" ");
        for(int k=1;k<=2*N-2*i+1;k++)
            printf("*");
        printf("\n");
    }
}