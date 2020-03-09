// 2447번 별 찍기 - 10
#include <bits/stdc++.h>
using namespace std;
// 9의 패턴은 공백으로 채워진 가운데의 3*3 정사각형을 3의 패턴으로 둘러싼 형태이다
// 좌표로 생각하면 출발점이 기준 
// 00 01 02 // 3 -> 1
// 00 03 06 // 9 -> 3
// 00 09 018 // 27 -> 9
char pos[2200][2200];
void square(int x, int y, int N)
{
    if(N == 1)
    {
        pos[x][y] = '*';
        return;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i == 1 && j == 1)
                continue;
            else
                square(x + i * N/3,y + j * N/3,N/3);
        }
    }
}
int main()
{
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            pos[i][j] = ' ';    // 초기화
    }
    square(0,0,N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            printf("%c",pos[i][j]);
        printf("\n");
    }
}