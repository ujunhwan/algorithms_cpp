// 10971번 외판원 순회 2
#include <bits/stdc++.h>
using namespace std;
int func(int n, int (*w)[10], int *a) {
    if(w[a[n-1]][a[0]] == 0) return -1;
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        if(w[a[i]][a[i+1]] == 0)
            return -1;
        sum += w[a[i]][a[i+1]];
    }
    sum += w[a[n-1]][a[0]];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int w[10][10], a[10];
    for(int i = 0; i < n; i++) {
        a[i] = i;
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    int ans = 1 << 24;
    do {
        int tmp = func(n, w, a);
        if(tmp < 0) continue;
        ans = min(ans, tmp);
    }
    while(next_permutation(a+1, a+n));
    cout << ans << '\n';
    return 0;
}