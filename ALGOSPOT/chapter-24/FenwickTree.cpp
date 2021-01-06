#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int>tree;
    FenwickTree(int n) : tree(n + 1) {}
    // psum[7] = tree[7] + tree[6] + tree[4];
    // 2진수 표현으로는 111 110 100 000
    // 마지막 비트를 지우면 다음 구간을 찾을 수 있다.
    int sum(int pos) {
        // 0부터 시작하므로, 1 늘려준다.
        pos++;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            // 다음 구간을 찾기 위해 최종 비트를 지운다!
            pos &= (pos - 1);
        }
        return ret;
    }

    // A[pos] += val 일 때, 펜윅 트리를 갱신하는 함수
    // A[5] += 3 일 때, tree[5], tree[6], tree[8], tree[16] 이 증가해야함
    // 2진수 표현으로 101, 110, 1000, 10000
    // 맨 오른쪽에 있는 1인 비트를 스스로에게 더해주는 연산을 반복하면, 갱신해야하는 트리의 위치를 알 수 있다.
    void add(int pos, int val) {
        pos++;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};