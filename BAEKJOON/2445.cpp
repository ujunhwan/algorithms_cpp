// 2445번 별 찍기 - 8
#include <bits/stdc++.h>
int main()
{
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
            printf("*");
        for(int k=1;k<=2*N-2*i;k++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("*");
        printf("\n");
    }
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<=N-i;j++)
            printf("*");
        for(int k=1;k<=2*i;k++)
            printf(" ");
        for(int l=1;l<=N-i;l++)
            printf("*");
        printf("\n");
    }
}