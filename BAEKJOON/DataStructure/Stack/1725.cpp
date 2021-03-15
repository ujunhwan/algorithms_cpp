// https://www.acmicpc.net/problem/1725
// 1725번 히스토그램

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n;
vector<int> h;

void solve() {
    cin >> n;
    h = vector<int> (n, 0);
    for(int i = 0; i < n; i++) cin >> h[i];
    h.push_back(0);
    
    int ans = 0;
    stack<int> st;

    // sweeping
    for(int i = 0; i <= n; i++) {
        while(!st.empty() && h[st.top()] >= h[i]) {
            // 현재보다 크다면 없앤다
            int left = st.top();
            st.pop();

            int width = i;
            if(!st.empty())
                width = i - st.top() - 1;
            
            ans = max(ans, h[left] * width);
        }

        st.push(i);
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}