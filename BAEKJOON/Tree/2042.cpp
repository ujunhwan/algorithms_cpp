// https://www.acmicpc.net/problem/2042
// 2042번 구간 합 구하기

#include <bits/stdc++.h>
using namespace std;

long long n, m, k, A[1000001];
vector<long long> tree;

long long sum(int pos) {
    long long ret = 0;
    while(pos > 0) {
        ret += tree[pos];
        pos &= (pos - 1);
    }
    return ret;
}

void add(int pos, long long val) {
    while(pos < tree.size()) {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

int main () {
    scanf("%lld %lld %lld", &n, &m, &k);
    tree = vector<long long> (n+1, 0);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
        add(i, A[i]);
    }

    for(int i = 0; i < m + k; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a == 1) {
            long long delta = c - A[b];
            A[b] = c;
            add(b, delta);
        }
        else {
            long long ans = sum(c) - sum(b-1);
            printf("%lld\n", ans);
        }
    }
}