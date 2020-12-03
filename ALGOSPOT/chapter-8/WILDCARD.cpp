#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
string W, S;
int cache[101][101];
bool solve(int w, int s) {
    int& ret = cache[w][s];
    if (ret != -1) return ret;
    int wn = W.size(), sn = S.size();
    if (w == wn) return ret = (s == sn);
    if (W[w] == S[s] || W[w] == '?') {
        return ret = solve(w+1, s+1);
    } 
    if (W[w] == '*') {
       if (solve(w+1, s) || (s < sn && solve(w, s+1))) return ret = 1;
    }
    return ret = 0;
}


// 종만북 풀이
bool matchMemorized(int w, int s) {
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    /*
    while(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        w += 1;
        s += 1;
    }
    */
    if(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
        return ret = matchMemorized(w + 1, s + 1);
    if(w == W.size()) return ret = (s == S.size());
    if(W[w] == '*') {
        if(matchMemorized(w + 1, s) || (s < S.size() && matchMemorized(w, s + 1)))
            return ret = 1;
    }
    /*
        for(int skip = 0; skip + s <= S.size(); skip++)
            if(matchMemorized(w + 1, s + skip))
                return ret = 1;
                */
    return ret = 0;
}


int main() {
    int tc; cin >> tc;
    while(tc--) {
        vector<string> ans;
        cin >> W;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            memset(cache, -1, sizeof(cache));
            cin >> S;
            if (solve(0, 0)) {
                ans.push_back(S);
            }
        }
        int m = ans.size();
        sort(ans.begin(), ans.end());
        for (int i = 0; i < m; i++) cout << ans[i] << '\n';
    }
    return 0;
}
/*
1
so?ve
2
solve
soave

1
he?p
3
help
heap
helpp

1
*p*
3
help
papa
hello
*/