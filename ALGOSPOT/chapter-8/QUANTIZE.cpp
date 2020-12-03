#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321;
int n, s, cache[101][11];
int psum[101], psqsum[101];

void precalc(vector<int>& q) {
    sort(q.begin(), q.end());
    psum[0] = q[0];
    psqsum[0] = q[0] * q[0];
    for(int i = 1; i < q.size(); i++) {
        psum[i] = psum[i-1] + q[i];
        psqsum[i] = psqsum[i-1] + q[i] * q[i];
    }
}

int minError(int a, int b) {
    int sum = psum[b] - (a == 0 ? 0 : psum[a - 1]);
    int sqsum = psqsum[b] - (a == 0 ? 0 : psqsum[a - 1]);
    int m = int(0.5 + (double)sum / (b - a + 1));
    int ret = sqsum - 2 * m * sum + m * m * (b - a + 1);
    return ret;
}

int quantize(vector<int>& q, int from, int parts) { 
    if(from == q.size()) return 0;
    if(parts == 0) return INF;
    int& ret = cache[from][parts];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 1; from + i <= q.size(); i++) {
        ret = min(ret, quantize(q, from + i, parts - 1) + minError(from, from + i - 1));
    }
    return ret;
}

int main() {
    int tc; cin >> tc;
    vector<int> ans;
    while(tc--) {
        memset(cache, -1, sizeof(cache));
        vector<int> q;
        cin >> n >> s;
        for(int i = 0; i < n; i++) {
            int t; cin >> t;
            q.push_back(t);
        }
        precalc(q);
        ans.push_back(quantize(q, 0, s));
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    return 0;
}