#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const static int mod = 20090711;

int solve(int n, int a, int b) {
    priority_queue<long long, vector<long long>, less<long long> > maxHeap;
    priority_queue<long long, vector<long long>, greater<long long> > minHeap;
    long long ret = 0;
    long long input = 1983;
    for(int i = 0; i < n; i++) {
        if(maxHeap.size() == minHeap.size())
            maxHeap.push(input);
        else
            minHeap.push(input);
        if(!maxHeap.empty() > 0 && !minHeap.empty() > 0 && maxHeap.top() > minHeap.top()) {
            int p = maxHeap.top(), q = minHeap.top();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(q); minHeap.push(p);
        }
        ret = (ret + maxHeap.top()) % mod;

        input = (input * (long long)a + (long long)b) % mod;
    }
    return ret;
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        int n, a, b; cin >> n >> a >> b;
        cout << solve(n, a, b) << '\n';
    }
    return 0;
}
