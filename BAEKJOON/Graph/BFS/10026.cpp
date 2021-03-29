// https://www.acmicpc.net/problem/10026
// 10026번 적록색약

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
int n, nor[101][101], abn[101][101];
string pic[101];

void norBfs(int y, int x, int num) {
    nor[y][x] = num;
    queue<pii> q;
    q.emplace(y, x);
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(nor[ny][nx] == -1 && pic[ny][nx] == pic[y][x]) {
                nor[ny][nx] = num;
                q.emplace(ny, nx);
            }
        }
    }
}

void abnBfs(int y, int x, int num) {
    abn[y][x] = num;
    queue<pii> q;
    q.emplace(y, x);
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(abn[ny][nx] == -1) {
                if(pic[ny][nx] == pic[y][x] || ((pic[ny][nx] == 'G' || pic[ny][nx] == 'R') && (pic[y][x] == 'G' || pic[y][x] == 'R'))) {
                    abn[ny][nx] = num;
                    q.emplace(ny, nx);
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> pic[i];

    memset(nor, -1, sizeof(nor));
    memset(abn, -1, sizeof(abn));
    int norCnt = 0, abnCnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(nor[i][j] == -1) 
                norBfs(i, j, ++norCnt);
            if(abn[i][j] == -1)
                abnBfs(i, j, ++abnCnt);
        }
    }

    cout << norCnt << " " << abnCnt << '\n';
}

int main() {
    fastio;
    solve();
}