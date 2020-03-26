// 1748번 수 이어 쓰기 1
#include <cstdio>
inline int pow(int x, int n){
    int a = 1;
    while(n--){
        a *= x;
    }
    return a;
}
int func(int n){
    int tmp = n * (9 * pow(10,n-1));
    return tmp;
}
int main(){
    int n; scanf("%d", &n);
    int length = 0;
    int num = n;
    while(num){
        num /= 10;
        length += 1;
    }
    long long ans = 0;
    for(int i=1;i<length;i++){
        ans += func(i);
    }
    ans += (n - pow(10, length - 1) + 1) * length;
    printf("%lld\n", ans);
    return 0;
}