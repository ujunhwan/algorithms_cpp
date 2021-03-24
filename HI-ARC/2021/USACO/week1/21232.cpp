// https://www.acmicpc.net/problem/21232
// 21232번 Comfortable Cows

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

int n, grid[3333][3333], ans, py, px;
queue<pii> q;

bool isComfortable(int y, int x) {
    bool ret = false;
    int cnt = 0;
    for(int k = 0; k < 4; k++) {
        int ny = y+d4y[k], nx = x+d4x[k];
        if(grid[ny][nx]) cnt++;
    }

    if(cnt == 3) {
        ret = true;
        for(int k = 0; k < 4; k++) {
            int ny = y+d4y[k], nx = x+d4x[k];
            if(!grid[ny][nx]) {
                // 새로 넣어야할 자리
                q.emplace(ny, nx);
            }
        }
    }
    
    return ret;
} 

void bfs(int y, int x) {
    if(grid[y][x] == 1) {
        --ans;
        return;
    }

    grid[y][x] = 1;
    q.emplace(y, x);
    isComfortable(y, x);
    for(int k = 0; k < 4; k++) {
        int ny = y+d4y[k], nx = x+d4x[k];
        if(grid[ny][nx]) isComfortable(ny, nx);
    }

    // added cow candidate -> push
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        // 새로 넣어야할 자리 중복 방지를 위해
        if(!grid[y][x]) {
            grid[y][x] = 1;
            ans++;

            // self check
            isComfortable(y, x);

            // adjacent check
            for(int k = 0; k < 4; k++) {
                int ny = y+d4y[k], nx = x+d4x[k];
                if(grid[ny][nx]) isComfortable(ny, nx);
            }
        }
    }
}

void solve() {
    memset(grid, 0, sizeof(grid));
    ans = 0;
    cin >> n;
    for(int x, y, i = 0; i < n; i++) {
        cin >> x >> y;
        bfs(y+1000, x+1000);
        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}

/*
8
0 0
1 0
2 0
3 0
4 0
1 1
2 1
3 1
*/