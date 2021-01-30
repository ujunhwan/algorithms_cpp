// https://www.acmicpc.net/problem/2512
// 2512번 예산

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321 * 2;
int n, m, a[10001], maxv;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        maxv = max(maxv, a[i]);
    }
    scanf("%d", &m);

    long long lo = 0, hi = maxv;
    long long ans = 0;
    while(lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long total = 0;

        for(int i = 0; i < n; i++)
            if(a[i] > mid) 
                total += mid;
            else 
                total += a[i];
        
        if(total > m) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
            ans = max(ans, mid);
        }
    }
    printf("%lld\n", ans);
}