// 1697번 숨바꼭질
#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 100000;
int n, k, dist[MAX + 1];
queue<int> q;
void bfs (int x) {
    q.push(x);
    dist[x] = 1;
    while (!q.empty()) {
        x = q.front(); q.pop();
        if (x == k) break;
        if (x-1 >= 0 && dist[x-1] == 0) {
            q.push(x-1);
            dist[x-1] = dist[x] + 1;
        }
        if (x+1 <= MAX && dist[x+1] == 0) {
            q.push(x+1);
            dist[x+1] = dist[x] + 1;
        }
        if (2*x <= MAX && dist[2*x] == 0) {
            q.push(2*x);
            dist[2*x] = dist[x] + 1;
        }
    }
}
int main() {
    scanf("%d %d", &n, &k);
    if (n == k) {
        puts("0");
        return 0;
    }
    bfs(n);
    printf("%d\n", dist[k] - 1);
    return 0;
}