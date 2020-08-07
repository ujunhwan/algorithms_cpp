// 9498번 시험 성적
#include <bits/stdc++.h>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    if (n <= 100 && n >= 90) {
        puts("A");
    } else if (n < 90 && n >= 80) {
        puts("B");
    } else if (n < 80 && n >= 70) {
        puts("C");
    } else if (n < 70 && n >= 60) {
        puts("D");
    } else {
        puts("F");
    }
    return 0;
}