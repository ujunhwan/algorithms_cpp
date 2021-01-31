// https://www.acmicpc.net/problem/12837
// 12837번 가계부 (Hard)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, q;
ll tree[4 * 1000000];

void update(int pos, int val) {
    while(pos <= n) {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

ll add(int pos) {
    ll ret = 0;
    while(pos) {
        ret += tree[pos];
        pos &= (pos - 1);
    }

    return ret;
}

int main() {
    scanf("%d %d", &n, &q);
    for(int a, b, c, i = 0; i < q; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) {
            update(b, c);
            continue;
        }

        ll ans = add(c) - add(b - 1);
        printf("%lld\n", ans);
    }
}