// https://www.acmicpc.net/problem/2805
// 2805번 나무 자르기

#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000001;
int n, m, tree[10000001];

int main() {
    scanf("%d %d", &n, &m);
    int maxv = -1, minv = INF;
    for(int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
        maxv = max(maxv, tree[i]);
    }

    int lo = 0, hi = maxv;
    long long ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        long long total = 0;
        for(int i = 0; i < n; i++)
            if(mid < tree[i])
                total += tree[i] - mid;
        if(total >= m) {
            if(ans < mid)
                ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    
    printf("%lld\n", ans);
}