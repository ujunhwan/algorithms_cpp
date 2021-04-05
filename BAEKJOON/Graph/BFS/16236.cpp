// https://www.acmicpc.net/problem/16236
// 16236번 아기 상어

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

int n, a[21][21], currLevel, currLeft;
pii currPos;

inline int calcDist(pii a, pii b) {
    return 0;
}

pii bfs(pii pos, int lvl, bool visited[][21]) {
    int dist[21][21];
    memset(dist, 0, sizeof(dist));
    dist[pos.first][pos.second] = 0;

    queue<pii> q;
    q.push(pos);

    vector<pii> ret;

    int y, x;
    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ny = y + d4y[k], nx = x + d4x[k];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(!dist[ny][nx] && a[ny][nx] <= lvl) {
                q.emplace(ny, nx);
                dist[ny][nx] = dist[y][x] + 1;
                if(a[ny][nx] != 0 && a[ny][nx] != lvl && !visited[ny][nx]) {
                    ret.emplace_back(dist[ny][nx], ny*n+nx);
                }
            }
        }
    }

    sort(ret.begin(), ret.end());
    // dist, position
    if(ret.size() == 0) return make_pair(-1, -1);
    return ret[0];
}

void solve() {
    currLevel = 2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 9) {
                currPos = make_pair(i, j);
                a[i][j] = 2;
            }
            else if(a[i][j] != 0) currLeft++;
        }
    }

    if(currLeft == 0) {
        puts("0");
        return;
    }

    bool visited[21][21];
    memset(visited, false, sizeof(visited));

    int ans = 0, exp = 0;
    while(currLeft) {
        visited[currPos.first][currPos.second] = true;
        pii res = bfs(currPos, currLevel, visited);
        if(res.first == -1) break;
        currLeft--;
        exp++;
        if(exp == currLevel) {
            exp = 0;
            currLevel++;
        }
        ans += res.first;
        currPos = make_pair(res.second/n, res.second%n);
        
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}