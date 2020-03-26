// 1107번 리모컨
#include <cstdio>
bool broken[10];
inline int abs(int x){
    return x > 0 ? x : -x;
}
inline int min(int a, int b){
    return a > b ? b : a;
}
inline int possible(int n){
    if(n == 0) return broken[n] ? 0 : 1;
    int length = 0;
    while(n){
        if(broken[n % 10]) return 0;
        n /= 10; length += 1;
    }
    return length;
}
int main(){
    int n; scanf("%d", &n);   
    int m; scanf("%d", &m);
    for(int i=0;i<m;i++){
        int tmp; scanf("%d", &tmp);
        getchar(); broken[tmp] = true;
    }
    int ans = abs(n - 100);
    for(int i=0;i<1000000;i++){
        if(possible(i)){
            ans = min(ans, possible(i) + abs(i - n));
        }
    }
    printf("%d\n", ans);
    return 0;
}
    