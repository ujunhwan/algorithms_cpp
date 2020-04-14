// 13549번 숨바꼭질 3
#include <cstdio>
#include <deque>
using namespace std;
const int MAX = 100000;
int n, k, dist[MAX+1];
deque<int> dq;
void bfs(int x) {
    dq.push_back(x);
    dist[x] = 1;
    while (!dq.empty()) {
        x = dq.front();
        dq.pop_front();
        if (x == k) {
            printf("%d\n", dist[x] - 1);
            return;
        }
        if (2*x <= MAX && dist[2*x] == 0) {
            dq.push_front(2*x);
            dist[2*x] = dist[x];
        }
        if (x+1 <= MAX && dist[x+1] == 0) {
            dq.push_back(x+1);
            dist[x+1] = dist[x] + 1;
        }
        if (x-1 >= 0 && dist[x-1] == 0) {
            dq.push_back(x-1);
            dist[x-1] = dist[x] + 1;
        }
    }
}
int main() {
    scanf("%d %d", &n, &k);
    bfs(n);
    return 0;
}