// 16964번 DFS 스페셜 저지
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int n, u, v, arr[100001];
bool vst[100001];
vector<int> adj[100001];
stack<int> st;
bool check(int x, int cur) {
    for (int i = 0; i < adj[cur].size(); i++)
        if (x == adj[cur][i]) return true;
    return false;
}
int go() {
    int idx = 0;
    vst[arr[idx]] = true;
    st.push(arr[idx++]);
    while (idx < n || !st.empty()) {
        int cur = st.top();
        int cnt = 0;
        for (int i = 0; i < adj[cur].size(); i++)
            if (!vst[adj[cur][i]]) cnt += 1;
        if (cnt == 0) {
            printf("%d pop!\n", st.top());
            st.pop();
            continue;
        }
        printf("count : %d\n", cnt);
        for (int i = 0; i < adj[cur].size(); i++) {
            if (check(cur, arr[idx])) {
                vst[arr[idx]] = true;
                printf("push : %d\n", arr[idx++]);
                st.push(arr[idx++]);
                break;
            } else return 0;
        }
    }
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[0] != 1) {
            puts("0");
            return 0;
        }
    }
    printf("%d\n", go());
    return 0;
}