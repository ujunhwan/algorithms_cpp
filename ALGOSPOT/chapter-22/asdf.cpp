#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
struct Node {
    int key;
    int priority;
    int size; // 이 노드를 루트로 하는 서브트리 크기
    Node* left, *right;
    Node(const int& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
    void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
    void setRight(Node* newRight) { right = newRight; calcSize(); }
    void calcSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
};
 
typedef pair<Node*, Node*> NodePair;
// root를 루트로 하는 트립을 key값과 비교하여 두 개의 트립으로 분리
NodePair split(Node* root, int key) {
    if (root == NULL)
        return NodePair(NULL, NULL);
    // 루트가 key 미만이면 오른쪽 서브트리를 split
    if (root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    // 루트가 key 이상이면 왼쪽 서브트리를 split
    else {
        NodePair ls = split(root->left, key);
        root->setLeft(ls.second);
        return NodePair(ls.first, root);
    }
}
// root를 루트로 하는 트립에 새 node를 삽입하여 결과 트립의 루트 반환
Node* insert(Node* root, Node* node) {
    if (root == NULL) return node;
    if (root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if (node->key < root->key) {
        root->setLeft(insert(root->left, node));
    }
    else
        root->setRight(insert(root->right, node));
    return root;
}
 
// a와 b가 두 개의 트립이고 max(a)<min(b)일 때 이 둘을 합친다
Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    if (a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    else {
        a->setRight(merge(a->right, b));
        return a;
    }
}
// root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트 반환
Node* erase(Node* root, int key) {
    if (root == NULL) return root;
    if (root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if (key < root->key)
        root->setLeft(erase(root->left, key));
    else
        root->setRight(erase(root->right, key));
    return root;
}
 
// root를 루트로 하는 트리 중에서 k번째 원소 반환
Node* kth(Node* root, int k) {
    int leftSize = 0;
    if (root->left != NULL) leftSize = root->left->size;
    if (k <= leftSize) return kth(root->left, k);
    if (k == leftSize + 1) return root;
    return kth(root->right, k - leftSize - 1);
}
 
// key보다 작은 키 값의 수 반환
int countLessThan(Node* root, int key)
{
    if (root == NULL)
        return 0;
    if (root->key >= key)
        return countLessThan(root->left, key);
    int ls = (root->left ? root->left->size : 0);
    return ls + 1 + countLessThan(root->right, key);
}
 
int C, N, A[50001], shifted[50001];
void solve() {
    Node* candidate = NULL;
    // 1 ~ N까지의 숫자를 모두 저장하는 트립 생성
    for (int i = 0; i < N; i++)
        candidate = insert(candidate, new Node(i + 1));
    // 뒤에서부터 A[]를 채워나간다
    for (int i = N - 1; i >= 0; i--) {
        // 후보 중 이 수보다 큰 수가 larger개 있다.
        int larger = shifted[i];
        Node* k = kth(candidate, i + 1 - larger);
        A[i] = k->key;
        candidate = erase(candidate, k->key);
    }
}
 
int main(){
    cin >> C;
    while (C--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> shifted[i];
        
        // 초기 배열 형태를 구합니다.
        solve();
        
        // 초기 배열 출력
        for (int i = 0; i < N; i++)
            cout << A[i] << " ";
        cout << endl;
    }
}