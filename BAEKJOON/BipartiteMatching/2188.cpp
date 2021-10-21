//
//

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int N, M;
vector<vector<bool> > adj;
vector<bool> vst;
vector<int> aMatch, bMatch;

bool dfs(int a) {
    if(vst[a]) return false;
    vst[a] = true;
    for(int b = 1; b <= M; b++) {
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
    cin >> N >> M;

    adj = vector<vector<bool> > (N+1, vector<bool>(M+1, false));

    for(int a = 0; a < N; a++) {
        int S; cin >> S;
        for(int j = 0; j < S; j++) {
            int b; cin >> b;
            adj[a][b] = true;
        }
    }

    aMatch = vector<int> (N+1, -1);
    bMatch = vector<int> (M+1, -1);

    int ans = 0;

    for(int i = 0; i < N; i++) {
        vst = vector<bool> (N+1, false);
        if(dfs(i)) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}