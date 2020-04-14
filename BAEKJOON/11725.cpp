// 11725번 트리의 부모 찾기
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100000;
int n, vst[MAX + 1], ans[MAX + 1];
vector<int> node[MAX + 1];
queue<int> q;
int main() {
    scanf("%d", &n);
    int minVal = 1 << 30, maxVal = -1;
    for (int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        node[x].push_back(y);
        node[y].push_back(x);
    }
    q.push(1);
    vst[1] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < node[x].size(); i++) {
            int nxt = node[x][i];
            if (vst[nxt] == 0) {
                q.push(nxt);
                vst[nxt] = vst[x] + 1;
                ans[nxt] = x;
            }
        }
    }
    for (int i = 2; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}