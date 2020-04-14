// 14226번 이모티콘
#include <cstdio>
#include <queue>
using namespace std;
int s, n, k, dist[1001][1001];
queue<pair<int, int> >q;
void bfs() {
    n = 1, k = 0;
    q.push(make_pair(n, k));
    dist[n][k] = 1;
    while (!q.empty()) {
        n = q.front().first; k = q.front().second;
        q.pop();
        if (n == s) {
            printf("%d\n", dist[s][k] - 1);
            return;
        }
        if (n >= 0 && dist[n][n] == 0) {
            q.push(make_pair(n, n));
            dist[n][n] = dist[n][k] + 1;
        }
        if (n + k <= 1000 && dist[n+k][k] == 0) {
            q.push(make_pair(n+k, k));
            dist[n+k][k] = dist[n][k] + 1;
        }
        if (n >= 1 && dist[n-1][k] == 0) {
            q.push(make_pair(n-1, k));
            dist[n-1][k] = dist[n][k] + 1;
        }
    }
}
int main() {
    scanf("%d", &s);
    bfs();
    return 0;
}