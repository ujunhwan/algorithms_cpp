#include <iostream>
#include <algorithm>
using namespace std;
int n, fence[20001];
int solve(int left, int right) {
    if (left == right) return fence[left];
    int mid = (left + right) / 2;
    int ret = max(solve(left, mid), solve(mid+1, right));
    int lo = mid, hi = mid + 1;
    int height = min(fence[lo], fence[hi]);
    ret = max(ret, height * 2);
    while (left < lo || right > hi) {
        if (lo > left && (hi == right || fence[lo-1] > fence[hi+1])) {
            lo --;
            height = min(fence[lo], height);
        } else {
            hi ++;
            height = min(fence[hi], height);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> fence[i];
        cout << solve(0, n-1) << '\n';
    }
}