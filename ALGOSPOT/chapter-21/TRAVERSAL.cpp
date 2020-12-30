#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

void postOrder(const vector<int>&preorder, const vector<int>&inorder) {
        if(preorder.empty()) return;

        int n = preorder.size();
        int root = preorder[0];
        int left, right;

        for(int i = 0; i < n; i++) {
            if(root == inorder[i]) {
                left = i;
                break;
            }
        }

        right = n - left - 1;

        postOrder(vector<int>(preorder.begin() + 1, preorder.begin() + left + 1), vector<int>(inorder.begin(), inorder.begin() + left));

        postOrder(vector<int>(preorder.begin() + left + 1, preorder.begin() + n), vector<int>(inorder.begin() + left + 1, inorder.begin() + n));

        cout << root << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;

    while(tc--) {
        vector<int>preorder, inorder;
        int n; cin >> n;

        int tmp;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            preorder.push_back(tmp);
        }

        for(int i = 0; i < n; i++) {
            cin >> tmp;
            inorder.push_back(tmp);
        }

        postOrder(preorder, inorder);
    }
    return 0;
}