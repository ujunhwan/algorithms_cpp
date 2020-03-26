// 6064번 카잉 달력
#include <cstdio>
#define max(a,b) a > b ? a : b
long long gcd(long long a, long long b){
    while(b){
        long long tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}
long long lcm(long long a, long long b){
    return (a/gcd(a,b)*b);
}
int main(){
    int t; scanf("%d", &t);
    long long m[t], n[t], x[t], y[t];
    for(int i=0;i<t;i++){
        scanf("%lld %lld %lld %lld", &m[i], &n[i], &x[i], &y[i]);
    }
    for(int k=0;k<t;k++){
        long long ans = -1;
        long long maxNum = lcm(m[k], n[k]);
        for(int i=x[k];i<=maxNum+1;i += m[k]){
            if((i-1) % m[k] + 1 == x[k] && (i-1) % n[k] + 1 == y[k]){
                ans = i;
                break;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}