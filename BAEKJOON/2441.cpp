// 2441번 별 찍기 - 4
#include <bits/stdc++.h>
int main()
{
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        for(int j=1;j<=i;j++)
            printf(" ");
        for(int k=1;k<=N-i;k++)       
            printf("*");
        printf("\n");
    }
}