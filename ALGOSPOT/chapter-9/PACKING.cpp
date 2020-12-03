#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string name[101];
int n, w, vol[101], need[101], choices[101];
int cache[101][1001];

int packing(int curr, int sum) {
    if(curr == n) return 0;
    int& ret = cache[curr][sum];
    if(ret != -1) return ret;
    ret = packing(curr + 1, sum);
    if(sum + vol[curr] <= w)
        ret = max(ret, packing(curr + 1, sum + vol[curr]) + need[curr]);
    return ret;
}

void reconstruct(int curr, int sum, vector<int>&seq) {
    if(curr == n) return;
    if(packing(curr, sum) == packing(curr + 1, sum)) {
        reconstruct(curr + 1, sum, seq);
    } else {
        seq.push_back(curr);
        reconstruct(curr + 1, sum + vol[curr], seq);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        vector<int> seq;
        memset(cache, -1, sizeof(cache));
        cin >> n >> w;
        for(int i = 0; i < n; i++)
            cin >> name[i] >> vol[i] >> need[i];

        int ans = packing(0, 0);
        reconstruct(0, 0, seq);
        cout << ans << " " << seq.size() << '\n';
        for(int i = 0; i < seq.size(); i++)
            cout << name[seq[i]] << '\n';
    }
    return 0;
}