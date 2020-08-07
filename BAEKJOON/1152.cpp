// 1152번 단어의 개수
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    char cur = ' ';
    char prv = ' ';
    int ans = 1;
    for (int i = 0; i < MAX; i++) {
        cur = cin.get();
        if (cur == '\n') {
            if (prv == ' ') ans -= 1;
            break;
        }
        if (prv != ' ' && cur == ' ') {
            ans += 1;
        }
        prv = cur;
    }
    cout << ans << '\n';
}