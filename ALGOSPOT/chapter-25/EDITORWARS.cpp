#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> rank, parent, enemy, size;
    UnionFind(int n) : rank(n, 1), parent(n), enemy(n, -1), size(n, 1) {
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if(u < 0) return -1;
        if(u == parent[u]) return u;
        return parent[u] =  find(parent[u]);
    }

    int merge(int u, int v) {
        if(u == -1 || v == -1) return max(u, v);
        u = find(u); v = find(v);
        if(u == v) return v;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        size[v] += size[u];
        return v;
    }

    bool ack(int u, int v) {
        u = find(u); v = find(v);
        if(rank[u] > rank[v]) swap(u, v);
        if(enemy[u] == v) return false;
        int a = merge(u, v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if(b != -1) enemy[b] = a;
        return true;
    }

    bool dis(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return false;
        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        bool contradiction = false;
        int N, M, a, b, c;
        string status;
        cin >> N >> M;
        UnionFind unionFind(N);

        int u = -1, v = -1;
        for(int i = 0; i < M; i++) {
            cin >> status >> a >> b;
            if(contradiction) continue;
            if(status[0] == 'A') {
                if(unionFind.ack(a, b) == false) {
                    contradiction = true;
                    cout << "CONTRADICTION AT " << i + 1 << '\n'; 
                }
                u = unionFind.find(a);
            }
            else {
                if(unionFind.dis(a, b) == false) {
                    contradiction = true;
                    cout << "CONTRADICTION AT " << i + 1 << '\n';
                }
            }
        }

        if(contradiction) continue;
        int ans = 0;
        for(int i = 0; i < N; i++) {
            if(i == unionFind.find(i)) {
                int enemy = unionFind.enemy[i];
                if(enemy > i) continue;
                int mySize = unionFind.size[i];
                int enemySize = (enemy == -1 ? 0 : unionFind.size[enemy]);
                ans += max(mySize, enemySize);
            }
        }
        cout << "MAX PARTY SIZE IS " << ans << '\n';
    }
    return 0;
}