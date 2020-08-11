// 2146번 다리 만들기
#include <bits/stdc++.h>
using namespace std;
static const int INF = 987654321;
static const int MAX = 101;
int n, arr[MAX][MAX], check[MAX][MAX];
stack<pair<int, int> >s;
int di[] = {0, 1, 0, -1}, dj[] = {-1, 0, 1, 0};
bool nearby (int i, int j) {
    if (i > 0 && !arr[i - 1][j]) return true;
    if (i < n - 1 && !arr[i + 1][j]) return true;
    if (j > 0 && !arr[i][j - 1]) return true;
    if (j < n - 1 && !arr[i][j + 1]) return true;
    return false;
}
void dfs(int y, int x, int num) {
    int i = y, j = x;
    arr[i][j] = num;
    check[i][j] = 1;
    s.push(make_pair(i, j));
    while(!s.empty()) {
        pair<int, int> cur = s.top(); s.pop();
        for(int k = 0; k < 4; k++) {
            int ii = cur.first + di[k];
            int jj = cur.second + dj[k];
            if (ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
            if (arr[ii][jj] > 0 && check[ii][jj] == 0) {
                arr[ii][jj] = num;
                check[ii][jj] = 1;
                s.push(cur);
                s.push(make_pair(ii, jj));
            }
        }
    }
}
int bfs(int i, int j) {
    queue<pair<int, int> >q;
    bool visited[MAX][MAX] = { 0 };
    int num = arr[i][j], cnt = 0;
    q.push({i, j});
    visited[i][j] = 1;
    while(!q.empty()) {
        int size = q.size();
        for (int k = 0; k < size; k++) {
            pair<int, int> cur = q.front(); q.pop();
            i = cur.first, j = cur.second;
            for (int l = 0; l < 4; l++) {
                int ni = i + di[l], nj = j + dj[l];
                if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                if (!visited[ni][nj] && arr[ni][nj] != num) {
                    if (arr[ni][nj]) {
                        return cnt;
                    }
                    visited[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0) check[i][j] = 0;
        }
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(check[i][j] == 0 && arr[i][j] > 0) {
                dfs(i, j, ++num);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans == 1) break;
            if (arr[i][j] && nearby(i, j)) {
                ans = min(ans, bfs(i, j));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}