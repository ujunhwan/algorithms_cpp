// 1182번 부분수열의 합
#include <bits/stdc++.h>
using namespace std;
int n, s, arr[20], ans;
void go (int a, int b) {
    if(a > -1 && b == s) 
        ans += 1;
    while(++a < n) {
        //cout << a << '\n';
        go(a, b + arr[a]);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i ++) 
        cin >> arr[i];
    go(-1, 0);   
    cout << ans << '\n';
    return 0;
}
