// 1991번 트리 순회
#include <cstdio>
using namespace std;
typedef struct _node {
    int left, right;
} Node;
Node a[52];
int n;
char x, y, z;
void preorder (int s) {
    if (s == -1) return;
    printf("%c", s + 'A');
    preorder(a[s].left);
    preorder(a[s].right);
}
void inorder (int s) {
    if (s == -1) return;
    inorder(a[s].left);
    printf("%c", s + 'A');
    inorder(a[s].right);
}
void postorder (int s) {
    if (s == -1) return;
    postorder(a[s].left);
    postorder(a[s].right);
    printf("%c", s + 'A');
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        getchar();
        scanf("%1c %1c %1c", &x, &y, &z);
        x -= 'A';
        if (y == '.') {
            a[x].left = -1;
        } else {
            a[x].left = y - 'A';
        }
        if (z == '.') {
            a[x].right = -1;
        } else {
            a[x].right = z - 'A';
        }
    }
    preorder(0); puts("");
    inorder(0); puts("");
    postorder(0); puts("");
    return 0;
}