// https://www.acmicpc.net/problem/1035
// 1035번 조각 움직이기

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

static const int INF = 14;

// right down left up
const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

int ans, visited[6][6], state;
string board[6];
vector<pair<int, int> > piece;
map<int, int> store;

inline int dist(int a, int b) {
    return abs(a/5 - b/5) + abs(a%5 - b%5);
}

int traverse(int y, int x) {
    int cnt = 1;
    visited[y][x] = 1;
    for(int k = 0; k < 4; k++) {
        int ny = y + d4y[k], nx = x + d4x[k];
        if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
        if(visited[ny][nx] == 0 && board[ny][nx] == '*') {
            cnt += traverse(ny, nx);
        }
    }
    return cnt;
}

bool isConnected() {
    memset(visited, false, sizeof(visited));
    if(traverse(piece[0].first, piece[0].second) == piece.size()) return true;
    return false;
}

void dfs(int cost, int state) {
    if(cost >= ans) return;
    if(isConnected()) {
        ans = min(ans, cost);
        return;
    }

    for(int i = 0; i < piece.size(); i++) {
        int y = piece[i].first, x = piece[i].second;
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || board[ny][nx] == '*') continue;

            int newState = state | (1 << (24-(ny*5+nx)));
            newState &= ~(1 << (24-(y*5+x)));
            
            if(store.count(newState) != 0 && store[newState] <= cost + 1) continue;
            store[newState] = cost + 1;

            piece[i] = make_pair(ny, nx);
            board[ny][nx] = '*';
            board[y][x] = '.';

            dfs(cost + 1, newState);

            piece[i] = make_pair(y, x);
            board[ny][nx] = '.';
            board[y][x] = '*';
        }
    }
}

void solve() {
    ans = INF;
    int init = 0;
    for(int i = 0; i < 5; i++) {
        cin >> board[i];
        for(int j = 0; j < 5; j++)
            if(board[i][j] == '*') {
                piece.push_back(make_pair(i, j));
                init |= (1 << (24-(i*5+j)));
            }
    }

    if(piece.size() == 1) {
        cout << 0 << '\n';
        return;
    }

    store[init] = 0;

    dfs(0, init);

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}