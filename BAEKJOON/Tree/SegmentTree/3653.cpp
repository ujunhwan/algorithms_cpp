// https://www.acmicpc.net/problem/3653
// 3653번 영화 수집

#include <bits/stdc++.h>
using namespace std;

int tc, n, m, tree[4 * 100001];

int sum(int pos) {
    int ret = 0;
    while(pos) {
        ret += tree[pos];
        pos &= (pos - 1);
    }

    return ret;
}

void update(int pos, int val) {
    while(pos <= n + m) {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        int pos[100001];
        memset(pos, 0, sizeof(pos));
        memset(tree, 0, sizeof(tree));
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++) {
            update(i + m + 1, 1);
            pos[i + 1] = i + m + 1;
        }

        for(int s, i = 0; i < m; i++) {
            scanf("%d", &s);
            printf("%d ", sum(pos[s]) - 1);

            int newPos = m - i;
            int oldPos = pos[s];
            pos[s] = newPos;

            update(newPos, 1);
            update(oldPos, -1);
        }

        printf("\n");
    }
}