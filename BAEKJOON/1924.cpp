// 1924번 2007년
#include <bits/stdc++.h>
int main()
{
    int x,y; scanf("%d %d",&x,&y);
    int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    char * week[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    for(int i=1;i<x;i++)
        y += month[i];
    printf("%s",week[y%7]);
}