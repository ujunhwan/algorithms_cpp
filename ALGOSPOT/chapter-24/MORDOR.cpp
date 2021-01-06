#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

struct RangeQuery { 
    int n;
    vector<int>rangeMax;
    vector<int>rangeMin;
    RangeQuery(const vector<int>& array) {
        n = array.size();
        rangeMax.resize(n * 4);
        rangeMin.resize(n * 4);
        initMax(array, 0, n - 1, 1);
        initMin(array, 0, n - 1, 1);
    }

    int initMax(const vector<int>&array, int left, int right, int node) {
        if(left == right)
            return rangeMax[node] = array[left];
        int mid = (left + right) / 2;
        int leftMax = initMax(array, left, mid, node * 2);
        int rightMax = initMax(array, mid + 1, right, node * 2 + 1);
        return rangeMax[node] = max(leftMax, rightMax);
    }

    int initMin(const vector<int>&array, int left, int right, int node) {
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = initMin(array, left, mid, node * 2);
        int rightMin = initMin(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    int queryMax(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left)
            return -1;
        if(left <= nodeLeft && nodeRight <= right)
            return rangeMax[node];
        int mid = (nodeLeft + nodeRight) / 2;
        int leftResult = queryMax(left, right, node * 2, nodeLeft, mid);
        int rightResult = queryMax(left, right, node * 2 + 1, mid + 1, nodeRight);
        return max(leftResult, rightResult);
    }

    int queryMin(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left)
            return numeric_limits<int>::max();
        if(left <= nodeLeft && nodeRight <= right)
            return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        int leftResult = queryMin(left, right, node * 2, nodeLeft, mid);
        int rightResult = queryMin(left, right, node * 2 + 1, mid + 1, nodeRight);
        return min(leftResult, rightResult);
    }

    int query(int left, int right) {
        return queryMax(left, right, 1, 0, n - 1) - queryMin(left, right, 1, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        int n, q; cin >> n >> q;
        vector<int>height(n, 0);
        for(int i = 0; i < n; i++)
            cin >> height[i];

        RangeQuery RangeQuery(height);
        int a, b;
        for(int i = 0; i < q; i++) {
            cin >> a >> b;
            cout << RangeQuery.query(a, b) << '\n';
        }
    }
    return 0;
}