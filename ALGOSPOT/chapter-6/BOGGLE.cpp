#include <iostream>
#include <string>
using namespace std;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
char map[5][5];
bool hasWord (const string &word, int x, int y) {
    if (x < 0 || y < 0 || x >= 5 || y >= 5) return false;
    if (word[0] != map[x][y]) return false; // 기저사례 1
    if (word.size() == 1) return true; // 기저사례 2
    for (int i = 0; i < 8; ++i) {
        int nextX = x + dx[i], nextY = y + dy[i];
        if (hasWord(word.substr(1), nextX, nextY) == true) return true;
    }
    return false;
}
int main() {
    int tc; cin >> tc;
    while (tc--) {
        for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> map[i][j];
        int n; cin >> n;
        string str[n];
        for (int i = 0; i < n; i++) {
            cin >> str[i];
            bool flag = false;
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (hasWord(str[i], j, k) == true) {
                        flag = true;
                    }
                }
            }
            if (flag) {
                cout << str[i] << " YES" << '\n';
            } else {
                cout << str[i] << " NO" << '\n';
            }
            str[i] = "";
        }
    }
    return 0;
}