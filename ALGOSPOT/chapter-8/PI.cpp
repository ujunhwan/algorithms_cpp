#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
string N;
int n;
const int INF = 987654321;
int cache[10002];

int classify(int a, int b) {
    // b is <= n-1
    string M = N.substr(a, b-a+1);
    if(string(M.size(), M[0]) == M) {
        return 1;
    }
    bool progressive = true;
    for(int i = 0; i < M.size() - 1; i++) {
        if(M[0] - M[1] != M[i] - M[i+1]) progressive = false;
    }
    if(progressive && abs(M[0] - M[1]) == 1) {
        return 2;
    }
    bool alternative = true;
    for(int i = 0; i < M.size(); i++) {
        if(M[i] != M[i%2]) alternative = false;
    }
    if(alternative) {
        return 4;
    }
    if(progressive) {
        return 5;
    }
    return 10;
}

int memorize(int start) {
    if(start >= n) return 0;
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 3; i <= 5; i++) {
        if(start + i <= n)
            ret = min(ret, classify(start, start + i - 1) + memorize(start + i));
    }
    return ret;
}


int main() {
    int tc; cin >> tc;
    vector<int> ans;
    while(tc--) {
        memset(cache, -1, sizeof(cache));
        cin >> N;
        n = N.size();
        ans.push_back(memorize(0));
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    return 0;
}