// https://www.acmicpc.net/problem/6549
// 6549번 히스토그램에서 가장 큰 직사각형

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<ll> h;

void solve() {
    while(1) {
        cin >> n;
        if(n == 0) return;
        h = vector<ll> (n);
        for(int i = 0; i < n; i++) cin >> h[i];
        h.push_back(0);

        stack<ll> st;

        ll ans = 0;
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && h[st.top()] >= h[i]) {
                int left = st.top();
                st.pop();

                int width = i;
                if(!st.empty()) width = i - st.top() - 1;
                ans = max(ans, h[left] * width);
            }

            st.push(i);
        }

        cout << ans << '\n';
    }
}

int main() {
    fastio;
    solve();
}