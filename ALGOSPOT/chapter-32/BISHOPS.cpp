#include <bits/stdc++.h>
using namespace std;

int tc, n, L, R;
char board[10][10];
int ll[10][10], rr[10][10];
int adj[100][100];

vector<bool> visited;
vector<int> aMatch, bMatch;

void lsearch(int i, int j, int num) {
    if(i < 0 || j < 0 || i >= n || j >= n) return;
    if(board[i][j] == '*' || ll[i][j] != -1) return;
    ll[i][j] = num;
    lsearch(i+1, j-1, num);
}

void rsearch(int i, int j, int num) {
    if(i < 0 || j < 0 || i >= n || j >= n) return;
    if(board[i][j] == '*' || rr[i][j] != -1) return;
    rr[i][j] = num;
    rsearch(i+1, j+1, num);
}

bool dfs(int a) {
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < R; b++)
        if(adj[a][b]) {
            if(bMatch[b] == -1 || dfs(bMatch[b])) {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }

    return false;
}

int bipariteMatch() {
    int size = 0;
    aMatch = vector<int> (L, -1);
    bMatch = vector<int> (R, -1);
    for(int i = 0; i < L; i++) {
        visited = vector<bool> (L, false);
        if(dfs(i)) size++;
    }

    return size;
}

void solve() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", board[i]);

    memset(ll, -1, sizeof(ll));
    memset(rr, -1, sizeof(rr));
    memset(adj, 0, sizeof(adj));

    L = 0; R = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == '.') {
                if(ll[i][j] == -1) lsearch(i, j, L++);
                if(rr[i][j] == -1) rsearch(i, j, R++);
            }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(ll[i][j] == -1 || rr[i][j] == -1) continue;
            adj[ll[i][j]][rr[i][j]] = 1;
        }
    
    printf("%d\n", bipariteMatch());
}

int main() {
    for(scanf("%d", &tc); tc--;) solve();
}