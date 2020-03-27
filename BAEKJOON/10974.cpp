// 10974번 모든 순열
#include <bits/stdc++.h>
using namespace std;
int arr[9];
bool func (int n) {
    int i = n;
    while (arr[i] < arr[i-1] && i > 1) {
        i -= 1;
    }
    if(i <= 1) return false;
    int target = i - 1;
    i = n;
    while (arr[target] > arr[i]) {
        i -= 1;
    }
    swap(arr[target], arr[i]);
    int j = target + 1;
    i = n;
    while (j < i){
        swap(arr[j], arr[i]);
        j += 1; i -= 1;
    }
    for(int l = 1; l <= n; l++) {
        cout << arr[l] << " ";
    }
    cout << '\n';
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << '\n';
    while(1) {
        if(func(n) == false)
            break;
    }
    return 0;
}