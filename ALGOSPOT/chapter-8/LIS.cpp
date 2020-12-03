#include <iostream>
#include <cstring>
using namespace std;
int n;
int s[501], cache[501];

int lis(int start) {
    int& ret = cache[start+1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start + 1; next < n; next++) {
        if(start == -1 || s[next] > s[start]) {
            ret = max(ret, lis(next) + 1);
        }
    }
    return ret;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(cache, -1, sizeof(cache));
        memset(s, 0, sizeof(s));
        cin >> n;
        for (int i = 0; i < n; i++) cin >> s[i];
        cout << lis(-1)-1 << '\n';
    }
    return 0;
}