// 10819번 차이를 최대로
#include <bits/stdc++.h>
using namespace std;
bool check;
int func (int n, int *a) {
    int ret = 0;
    for (int k = 2; k <= n; k++) {
        ret += abs(a[k] - a[k-1]);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int arr[10];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + (n + 1));
    int ans = 0;
    while(next_permutation(arr + 1, arr + (n + 1))) {
        ans = max(ans, func(n ,arr));
    } 
    cout << ans << '\n';
    return 0;
}