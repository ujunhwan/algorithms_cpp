// https://www.acmicpc.net/problem/11505
// 11505번 구간 곱 구하기

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;
int n, m, k, a[1000009];
ll tree[1000001 * 4];

ll init(int node, int start, int end) {
    if(node <= 0) return 1;
    if(start == end)
        return tree[node] = a[start];

    ll leftChild = init(node * 2, start, (start + end) / 2) % MOD;
    ll rightChild = init(node * 2 + 1, (start + end) / 2 + 1, end) % MOD;

    return tree[node] = (leftChild * rightChild) % MOD;
}

ll update(int node, int start, int end, int pos, int val) {
    if(node <= 0) return 1;
    if(!(start <= pos && pos <= end))
        return tree[node];

    if(start == end)
        return tree[node] = val;

    ll leftChild = update(node * 2, start, (start + end) / 2, pos, val) % MOD;
    ll rightChild = update(node * 2 + 1, (start + end) / 2 + 1, end, pos, val) % MOD;

    return tree[node] = (leftChild * rightChild) % MOD;
}

ll multiply(int node, int start, int end, int left, int right) {
    if(node <= 0) return 1;
    if(left > end || right < start)
        return 1;

    if(left <= start && end <= right)
        return tree[node];
    
    ll leftChild = multiply(node * 2, start, (start + end) / 2, left, right) % MOD;
    ll rightChild = multiply(node * 2 + 1, (start + end) / 2 + 1, end, left, right) % MOD;

    return (leftChild * rightChild) % MOD;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    init(1, 1, n);

    for(int a, b, c, i = 0; i < m + k; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) {
            update(1, 1, n, b, c);
            continue;
        }

        ll ans = multiply(1, 1, n, b, c) % MOD;

        printf("%lld\n", ans);
    }
}