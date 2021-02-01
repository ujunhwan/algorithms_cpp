// https://www.acmicpc.net/problem/2357
// 2357번 최솟값과 최댓값

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 9876543210;
int n, m, arr[100001];
ll treeMax[4 * 100001], treeMin[4 * 100001];

ll initMax(int node, int start, int end) {
    if(start == end)
        return treeMax[node] = arr[start];
    
    ll leftChild = initMax(node * 2, start, (start + end) / 2);
    ll rightChild = initMax(node * 2 + 1, (start + end) / 2 + 1, end);

    return treeMax[node] = max(leftChild, rightChild);
}

ll initMin(int node, int start, int end) {
    if(start == end)
        return treeMin[node] = arr[start];
    
    ll leftChild = initMin(node * 2, start, (start + end) / 2);
    ll rightChild = initMin(node * 2 + 1, (start + end) / 2 + 1, end);

    return treeMin[node] = min(leftChild, rightChild);
}

ll queryMax(int node, int start, int end, int left, int right) {
    if(start > right || end < left)
        return -1;
    
    if(left <= start && end <= right)
        return treeMax[node];
    
    ll leftChild = queryMax(node * 2, start, (start + end) / 2, left, right);
    ll rightChild = queryMax(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return max(leftChild, rightChild);
}

ll queryMin(int node, int start, int end, int left, int right) {
    if(start > right || end < left)
        return INF;
    
    if(left <= start && end <= right)
        return treeMin[node];
    
    ll leftChild = queryMin(node * 2, start, (start + end) / 2, left, right);
    ll rightChild = queryMin(node * 2 + 1, (start + end) / 2 + 1, end, left, right);

    return min(leftChild, rightChild);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    initMax(1, 0, n - 1);
    initMin(1, 0, n - 1);

    for(int a, b, i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ll p = queryMax(1, 0, n - 1, a - 1, b - 1);
        ll q = queryMin(1, 0, n - 1, a - 1, b - 1);

        printf("%lld %lld\n", q, p);
    }
}