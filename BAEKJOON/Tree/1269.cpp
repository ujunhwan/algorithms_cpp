// https://www.acmicpc.net/problem/1269
// 1269번 대칭 차집합

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    unordered_set<int> A;
    for(int s, i = 0; i < a; i++) {
        scanf("%d", &s);
        A.insert(s);
    }

    int inter = 0;
    for(int s, i = 0; i < b; i++) {
        scanf("%d", &s);
        if(A.find(s) != A.end()) inter++;
    }
    
    int ans = a + b - inter * 2;
    printf("%d\n", ans);
}