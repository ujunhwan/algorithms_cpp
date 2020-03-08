// 2440번 별 찍기 - 3
#include <bits/stdc++.h>
int main()
{
    int N; scanf("%d",&N);
    while(N)
    {
        for(int i=1;i<=N;i++)
            printf("*");
        printf("\n");
        N--;
    }
}