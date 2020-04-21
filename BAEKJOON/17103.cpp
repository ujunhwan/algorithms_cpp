// 17103번 골드바흐 파티션
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
static const int bufSize = 1 << 20;
bitset <bufSize> prime;
inline bool isPrime(int n) {
    if (n > 2 && n % 2 == 0) return false;
    return prime.test(n) ? false : true;
}
int main() {
    for(int i = 3; i <= 1000; i += 2) {
        if(!prime.test(i))
            for(int j = i + i; j <= bufSize; j += i)
                prime.set(j);
    }
    int t; scanf("%d", &t);
    while(t--) {
        int n, cnt = 0; scanf("%d", &n);
        for(int i = 2; i <= n / 2; i++) {
            int a = n - i, b = i;
            if(isPrime(a) && isPrime(b)) cnt++;
            if (i == 2) continue; i++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}