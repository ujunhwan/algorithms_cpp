// 11723번 집합
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    int s = 0;
    int length = 20;
    while (n--) {
        char str[100]; int x;
        scanf("%s", str);
        if(!strcmp(str, "add")) {
            scanf("%d", &x);
            s |= 1 << x - 1;
        } else if(!strcmp(str, "check")) {
            scanf("%d", &x); 
            int result = s & (1 << x - 1);
            if(result) puts("1");
            else puts("0");
        } else if(!strcmp(str, "toggle")) {
            scanf("%d", &x);
            s ^= 1 << x - 1;
        } else if(!strcmp(str, "remove")) {
            scanf("%d", &x);
            s &= ~(1 << x - 1);
        } else if(!strcmp(str, "empty")) {
            s = 0;
        } else if(!strcmp(str, "all")) {
            s = (1 << length) - 1;
        }
    }
    return 0;
}