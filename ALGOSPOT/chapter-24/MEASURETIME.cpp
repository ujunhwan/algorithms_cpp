#include <cstdio>
#include <vector>
using namespace std;

struct FenwickTree {
    vector<int>tree;
    FenwickTree(int n) : tree(n + 1) {}

    int sum(int pos) {
        pos++;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, int val) {
        pos++;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }

};

int main() {
    int T;
    for(scanf("%d", &T); T--;) {
        int N; 
        scanf("%d", &N);

        vector<int>A(N, 0);
        for(int i = 0; i < N; i++)
            scanf("%d", &A[i]);
        
        FenwickTree tree(1000000);
        long long ans = 0;
        for(int i = 0; i < A.size(); i++) {
            ans += tree.sum(999999) - tree.sum(A[i]);
            tree.add(A[i], 1);
        }

        printf("%lld\n", ans);
    }
    return 0;
}