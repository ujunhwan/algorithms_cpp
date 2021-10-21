// https://www.acmicpc.net/problem/9576
// 9576번 책 나눠주기

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int N, M, taken[1011];
vector<int> aMatch, bMatch;
vector<bool> vst;
int adj[1011][1011];

// 학생 idx
bool dfs(int a) {
    if(vst[a] == 1) return false;
    vst[a] = 1;
    for(int b = 1; b <= N; b++) {
        // b -> 책 #
        if(adj[a][b]) {
            if(bMatch[b] == -1 || dfs(bMatch[b])) {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }

    return false;
}

void solve() {
    int tc; cin >> tc;
    while(tc--) {
        memset(adj, 0, sizeof(adj));
        cin >> N >> M;

        aMatch = vector<int> (M+2, -1);
        bMatch = vector<int> (N+2, -1);

        for(int s, e, i = 0; i < M; i++) {
            cin >> s >> e;
            for(int j = s; j <= e; j++) {
                adj[i][j] = 1;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < M; i++) {
            vst = vector<bool> (M, false);
            if(dfs(i)) {
                ans += 1;
            }
        }

        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}

/*
    그리디 인지 알았는데, 이분 매칭 문제였다.
*/