// https://www.acmicpc.net/problem/3055
// 3055번 탈출

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

int R, C;
string forest[51];
pii start, goal;
vector<pii> water;
vector<vector<int> > w;
vector<vector<int> > dist;

void waterBfs(pii src) {
    w[src.first][src.second] = 0;
    queue<pii> q;
    q.push(src);

    int y, x;
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if(forest[ny][nx] == 'X' || forest[ny][nx] == '*' || forest[ny][nx] == 'D' || forest[ny][nx] == 'S') continue;
            if(w[ny][nx] == -1 || w[ny][nx] > w[y][x]+1) {
                w[ny][nx] = w[y][x]+1;
                if(forest[ny][nx] != 'D')
                    q.push({ny, nx});
            }
        }
    }
}

void bfs(pii src) {
    dist[src.first][src.second] = 0;
    queue<pii> q;
    q.push(src);

    int y, x;
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        if(forest[y][x] == 'D') return;
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if(forest[ny][nx] == 'X' || forest[ny][nx] == '*') continue;
            if(w[ny][nx] != -1 && w[ny][nx] <= dist[y][x]+1) continue;
            if(forest[ny][nx] == 'D' || dist[ny][nx] == -1 || dist[ny][nx] > dist[y][x]+1) {
                dist[ny][nx] = dist[y][x]+1;
                q.push({ny, nx});
            }
        }
    }
}

void solve() {
    w = vector<vector<int> > (51, vector<int>(51, -1));
    dist = vector<vector<int> > (51, vector<int>(51, -1));
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        cin >> forest[i];
        for(int j = 0; j < forest[i].size(); j++) {
            if(forest[i][j] == '.' || forest[i][j] == 'X') continue;
            else if(forest[i][j] == 'D') goal = {i, j};
            else if(forest[i][j] == 'S') start = {i, j};
            else if(forest[i][j] == '*') water.push_back({i, j});
        }
    }

    for(int i = 0; i < water.size(); i++) waterBfs(water[i]);
    bfs(start);

    int ans = dist[goal.first][goal.second];
    if(ans == -1) cout << "KAKTUS" << '\n';
    else cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}

/*
3 3
S..
.D.
...
*/