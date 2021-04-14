// https://www.acmicpc.net/problem/18319
// 18319번 Berry Picking

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

int N, K;
vector<int> a;

void solve() {
    cin >> N >> K;
    a = vector<int>(N);
    for(int& el : a) cin >> el;

    sort(a.begin(), a.end(), greater<int>());

    ll ans = 0;
    // pick : berry 최대 갯수
    for(ll pick = 1; pick <= a[0]; pick++) {
        ll cnt = 0;

        // K <= cnt -> 전부 pick개가 담김
        // K > cnt -> 몇개는 빠짐..
        for(int i = 0; i < N; i++) cnt += a[i]/pick;

        if(K <= cnt) {
            ans = max(ans, pick*(K/2));
        } else {
            vector<int> b;
            for(int i = 0; i < N; i++) b.push_back(a[i]%pick);
            sort(b.begin(), b.end(), greater<int>());

            // K/2 보다 작으면 pick은 동생에게
            if(cnt < K/2) {
                ll cand = 0;
                for(int i = 0; i < N; i++) {
                    if(cnt > K/2 && cnt <= K) cand += b[i];
                    cnt++;
                }
                ans = max(ans, cand);
            } else {
                ll cand = pick*(cnt-K/2);
                for(int i = 0; i < N; i++) {
                    if(cnt == K) break;
                    cand += b[i];
                    cnt++;
                }
                ans = max(ans, cand);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}