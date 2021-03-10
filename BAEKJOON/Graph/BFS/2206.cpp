// https://www.acmicpc.net/problem/2206
// 2206번 벽 부수고 이동하기

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

vector<string> a;
vector<pair<int, int> > wallPos;
int n, m;
int dist[1001][1001];

void bfs() {
    dist[0][0] = 1;
    queue<int> q;
    queue<int> q2;
    q.push(0);
    while(!q.empty()) {
        int y = q.front()/m, x = q.front()%m;
        q.pop();
        if(y == n - 1 && x == m - 1) continue;
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(dist[ny][nx] == 0) {
                if(a[ny][nx] == '0') q.push(ny*m+nx);
                else if(a[ny][nx] == '1') q2.push(ny*m+nx);
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }

    while(!q2.empty()) {
        int y = q2.front()/m, x = q2.front()%m;
        q2.pop();
        if(y == n - 1 && x == m - 1) continue;
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == '1') continue;
            if(dist[ny][nx] != 0 && dist[ny][nx] <= dist[y][x] + 1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q2.push(ny*m+nx);
        }
    }
}

// 벽까지의 최소거리 + 벽에서부터의 최소거리
void solve() {
    memset(dist, 0, sizeof(dist));
    cin >> n >> m;
    a = vector<string>(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    bfs();
    cout << (dist[n-1][m-1] == 0 ? -1 : dist[n-1][m-1]) << '\n';
}


int main() {
    fastio;
    solve();
}