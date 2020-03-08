// 11721번 열 개씩 끊어 출력하기
#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    string str;
    getline(cin,str);
    int length = str.size();
    for(int i=0;i<length;i++)
    {
        printf("%c",str[i]);
        if((i+1)%10 == 0)
            printf("\n");
    }
}