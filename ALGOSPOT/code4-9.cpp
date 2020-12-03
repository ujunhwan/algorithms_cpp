#include <bits/stdc++.h>
using namespace std;
int vmin = numeric_limits<int>::min();
int inefficientMaxSum(const vector<int> &a) {   // O(N^3)
    int n = a.size(), ret = vmin;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int vsum = 0;
            for (int k = i; k <= j; ++k)
                vsum += a[k];
            ret = max(ret, vsum);
        }
    }
    return ret;
}
int betterMaxSum(const vector<int> &a) {    // O(N^2)
    int n = a.size(), ret = vmin;
    for (int i = 0; i < n; ++i) {
        int vsum = 0;
        for (int j =i; j < n; ++j) {
            vsum += a[j];
            ret = max(ret, vsum);
        }
    }
    return ret;
}
int fastMaxSum(const vector<int> &a, int lo, int hi) {  // O(NlgN) 분할정복
    if(lo == hi) return a[lo]; // 구간의 길이가 1일경우
    int mid = (lo + hi) / 2;
    int left = vmin, right = vmin, vsum = 0;
    for (int i = mid; i <= lo; --i) {
        vsum += a[i];
        left = max(left, vsum);
    }
    vsum = 0;
    for (int j = mid + 1; j <= hi; ++j) {
        vsum += a[j];
        right = max(right, vsum);
    }
    int single = max(fastMaxSum(a, lo, mid), fastMaxSum(a, mid+1, hi));
    return max(left+right, single); // 두개 합친거랑 각각의 구간에 있는거랑 더 큰거 리턴
}
int fastestMaxSum(const vector<int> &a) {   // O(N) DP
    int n = a.size(), ret = vmin, psum = 0;
    for (int i = 0; i < n; ++i) {
        psum = max(psum, 0) + a[i];
        printf("index : %d psum : %d\n", i, psum);
        ret = max(psum, ret);
    }
    return ret;
}
int main() {
    int arr[] = {-7, 4, -3, 6, 3, -8, 3, 4}; // 4 -3 6 3 -> 10 maxvalue
    vector<int> a (arr, arr + sizeof(arr) / sizeof(arr[0]));
    fastestMaxSum(a);
    return 0;
}
