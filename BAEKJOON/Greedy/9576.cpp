// https://www.acmicpc.net/problem/9576
// 9576번 책 나눠주기

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
vector<int> a, b;

bool cmp(pii a, pii b) {
    if(a.first == b.first) {
        return a.second-a.first < b.second-b.first;
    }
    return a.second < b.second;
}

void solve() {
    int tc; cin >> tc;
    while(tc--) {
        vector<pii> delta;

        // 답 상한선 N
        cin >> N >> M;

        a = vector<int> (M+1);
        b = vector<int> (M+1);

        for(int i = 0; i < M; i++) {
            cin >> a[i] >> b[i];
            delta.push_back(make_pair(a[i], b[i]));
        }

        sort(delta.begin(), delta.end(), cmp);

        int ans = 0;

        vector<bool> taken(N+2, false);
        for(int i = 0; i < M; i++) {
            int start, end;
            start = delta[i].first;
            end = delta[i].second;

            for(int j = start; j <= end; j++) {
                if(!taken[j]) {
                    taken[j] = 1;
                    ans++;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}