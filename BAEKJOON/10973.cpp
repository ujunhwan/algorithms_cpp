// 10973번 이전 순열
#include <bits/stdc++.h>
using namespace std;
int arr[10001];
bool func(int n) {
    int i = n;
    while(arr[i] > arr[i - 1]) {
        i -= 1;
    }
    if(i <= 0) return false;
    int target = i - 1;
    i = n;
    while(arr[target] < arr[i]) {
        i -= 1;
    }
    swap(arr[i], arr[target]);
    i = n;
    int j = target + 1;
    while(j < i) {
        swap(arr[j], arr[i]);
        j += 1; i -= 1;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    if(func(n) == false) {
        cout << "-1" << '\n';
        return 0;
    }
    for(int i=1;i<=n;i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
    return 0;
}