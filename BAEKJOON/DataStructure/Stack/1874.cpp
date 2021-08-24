// https://www.acmicpc.net/problem/1874
// 1874번 스택 수열

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};
const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, arr[100001], st[100001];

int currIdx;

void push(int val) {
    st[++currIdx] = val;
}

void pop() {
    st[currIdx--] = -1;
}

void solve() {
    memset(st, -1, sizeof(st));
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int aIdx = 0;
    int ansLen = 0;
    char ans[100001*2];
    int val = 1;

    for(int i = 0; i < 2*n+1; i++) {
        if(aIdx == n) break;
        if(st[currIdx] < arr[aIdx]) {
            push(val++);
            ans[ansLen++] = '+';
        } else if(st[currIdx] > arr[aIdx]) {
            pop();
            ans[ansLen++] = '-';
        } else {
            pop();
            ans[ansLen++] = '-';
            aIdx++;
        }
    }

    if(aIdx != n) cout << "NO" << '\n';
    else for(int i = 0; i < ansLen; i++) cout << ans[i] << '\n';
}

int main() {
    fastio;
    solve();
}