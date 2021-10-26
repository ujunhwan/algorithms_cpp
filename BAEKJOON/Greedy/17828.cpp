// https://www.acmicpc.net/problem/17828
// 17828번 문자열 화폐

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static const int INF = 0x7f7f7f7f;

int N, X;
vector<char> ans;

void solve() {
    cin >> N >> X;
    if(26*N < X || N > X) {
        cout << "!";
        return;
    }
    int aMax = 0;
    for(int i = N-1; i >= 0; i--) {
        int leftDigit = N-i;
        int leftValue = X-i;
        if(leftValue == 0) {
            aMax = i;
            break;
        } 
        if(leftValue / leftDigit < 26) {
            aMax = i;
            break;
        }
    }

    int zMax = 0;
    int val = 0;
    for(int i = 0; i <= N-aMax; i++) {
        if(X-aMax-i*26 < 26) {
            zMax = i;
            val = X-aMax-i*26;
            break;
        }
    }
    
    for(int i = 0; i < aMax; i++) {
        cout << "A";
    }
    if(val != 0) {
        cout << (char)('A'-1+val);
    }
    for(int i = 0; i < zMax; i++) {
        cout << "Z";
    }
}

int main() {
    fastio;
    solve();
}

/*

6 64
ans : AAAIZZ

6 157

3 6
ans : AAD

*/