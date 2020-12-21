#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

static const int limit = 5000000;
static const long long mod = (1LL << 32);
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    while(tc--) {
        int k, n; cin >> k >> n;
        queue<int> q;
        int ret = 0; 
        long long a = 1983, psum = 0;

        for(int i = 0; i < n; i++) {
            int signal = a % 10000 + 1;
            psum += signal;
            q.push(signal);

            while(psum > k) {
                psum -= q.front();
                q.pop();
            }

            if(psum == k) ret++;

            a = (a * 214013 + 2531011) % mod;
        }
        cout << ret << '\n';
    }

    return 0;
}

/*
3
8791 20
5265 5000
3578452 5000000
*/