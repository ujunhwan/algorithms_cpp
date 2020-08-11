// 2602번 돌다리 건너기
#include <bits/stdc++.h>
using namespace std;
string word, bridge[2];
int cache[2][101][21];
int go(bool state, int b, int w) {
    int& ret = cache[state][b][w];
    if (w < word.size() && b >= bridge[0].size()) return ret = 0;
    if (w >= word.size()) return ret = 1;
    if (ret != -1) return ret;
    int total = 0;
    for (int i = b; i < bridge[0].size(); i++) {
        if (word[w] == bridge[!state][i]) {
            total += go(!state, i + 1, w + 1);
        }
    }
    return ret = total;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> word >> bridge[0] >> bridge[1];
    int n = bridge[0].size(), m = word.size();
    cout << go(false, 0, 0) + go(true, 0, 0) << '\n';
    return 0;
}
/*
RRRRRRRRRR
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
*/