// 13913번 숨바꼭질 4
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 100000;
int n, k, dist[MAX + 1], prv[MAX + 1];
queue<int> q;
stack<int> s;
void bfs(int x) {
    q.push(x);
    dist[x] = 1;
    while (!q.empty()) {
        x = q.front(); q.pop();
        if (x == k) break;
        if (x-1 >= 0 && dist[x-1] == 0) {
            q.push(x-1);
            prv[x-1] = x;
            dist[x-1] = dist[x] + 1;
        }
        if (x+1 <= MAX && dist[x+1] == 0) {
            q.push(x+1);
            prv[x+1] = x;
            dist[x+1] = dist[x] + 1;
        }
        if (2*x <= MAX && dist[2*x] == 0) {
            q.push(2*x);
            prv[2*x] = x;
            dist[2*x] = dist[x] + 1;
        }
    }
}
int main () {
    scanf("%d %d", &n, &k);
    if (n == k) {
        printf("%d\n%d", 0, n);
        return 0;
    }
    bfs(n);
    printf("%d\n", dist[k] - 1);
    int now = k;
    s.push(now);
    while (!s.empty()) {
        now = prv[now];
        s.push(now);
        if (now == n) {
            while (!s.empty()) {
                now = s.top(); s.pop();
                printf("%d ", now);
            }
        }
    }
    return 0;
}