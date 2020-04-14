// 2250번 트리의 높이와 너비
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int left, right;
};
int n, x, y, z, idx, seq[10001], depthMax, root;
bool isChild[10001];
vector<int> level[10001];
node a[10001];
void inorder (int s, int depth) {
    if (s == -1) return;
    inorder(a[s].left, depth + 1);
    level[depth].push_back(s);
    if (depthMax < depth) depthMax = depth;
    seq[s] = ++idx;
    inorder(a[s].right, depth + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        a[x].left = y;
        a[x].right = z;
        if (y != -1) isChild[y] = true; 
        if (z != -1) isChild[z] = true;
    }
    if (n == 1) {
        printf("%d %d\n", 1, 0);
        return 0;
    }
    for (int i = 1; i <= n; i++) 
        if (!isChild[i]) root = i;
    inorder(root, 1);
    pair<int, int> ans;
    for (int i = 1; i <= depthMax; i++) {
        int last = level[i].size() - 1;
        int length = seq[level[i][last]] - seq[level[i][0]] + 1;
        if (length > ans.second) {
            ans.first = i;
            ans.second = length;
        }
    }
    printf("%d %d\n", ans.first, ans.second);
    return 0;
}