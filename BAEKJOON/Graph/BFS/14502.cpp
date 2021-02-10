// https://www.acmicpc.net/problem/14502
// 14502번 연구소

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef pair<int, int> pii;

struct pos {
    pos(int y, int x) : y(y), x(x) {}
    int y, x;
};

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
int n, m;
vector<vector<int> > a;
vector<pos> virus;

int bfs(vector<vector<int> > visited) {
    // y first, x second
    queue<pos> q;
    for(int i = 0; i < virus.size(); i++) {
        visited[virus[i].y][virus[i].x] = 2;
        q.push(virus[i]);
    }
   
    while(!q.empty()) {
        int cy = q.front().y, cx = q.front().x;
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ny = cy + d4y[k], nx = cx + d4x[k];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx]) {
                q.push(pos(ny, nx));
                visited[ny][nx] = 2;
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!visited[i][j]) ret++;
    return ret;
}

int brute(int cnt, pos st, vector<vector<int> > visited) {
    if(cnt == 3) {
        return bfs(visited);
    }
    int ret = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!visited[i][j]) {
                visited[i][j] = 1;
                ret = max(ret, brute(cnt+1, pos(i, j), visited));
                visited[i][j] = 0;
            }
    return ret;
}

void solve() {
    // n height m width
    cin >> n >> m;
    a = vector<vector<int> > (n, vector<int>(m));
    int oneCnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) virus.push_back(pos(i, j));
            else if(a[i][j] == 1) oneCnt++;
        }
    int ans = oneCnt > 0 ? brute(0, pos(0, 0), a) : 3;
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}