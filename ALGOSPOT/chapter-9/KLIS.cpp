#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 2000000001;
int n, k, l, A[501];
int cacheLen[501], cacheCnt[501];

int lis(int start) {
    if(start == n) return 0;
    int& ret = cacheLen[start + 1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start + 1; next < n; next++) {
        if(start == -1 || A[start] < A[next])
            ret = max(ret, lis(next) + 1);
    }
    return ret;
}

int count(int start) {
    if(lis(start) == 1) return 1;
    int& ret = cacheCnt[start + 1];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = start + 1; next < n; next++) {
        if((start == -1 || A[start] < A[next]) && lis(start) == lis(next) + 1) {
            ret = min<long long>(INF, (long long)ret + count(next));
        }
    }
    return ret;
}

void reconstruct(int start, int skip, vector<int>& vec) {
    if(start != -1) vec.push_back(A[start]);
    vector<pair<int, int> > followers;
    for(int next = start + 1; next < n; next++) {
        if((start == -1 || A[start] < A[next]) && lis(start) == lis(next) + 1)
            followers.push_back(make_pair(A[next], next));
    }
    sort(followers.begin(), followers.end());
    for(int i = 0; i < followers.size(); i++) {
        int idx = followers[i].second;
        if (skip > count(idx)) {
            skip -= count(idx);
        } else {
            reconstruct(idx, skip, vec);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        memset(cacheLen, -1, sizeof(cacheLen));
        memset(cacheCnt, -1, sizeof(cacheCnt));
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> A[i];
        l = lis(-1) - 1;
        cout << l << '\n';
        vector<int> ans;
        reconstruct(-1, k, ans);
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << '\n';
    }
}
/*
1
5 3
1 2 5 3 4

1
6 3 
1 5 4 3 2 10

3
=========
1 2 10
1 3 10
1 4 10 <--
1 5 10
*/