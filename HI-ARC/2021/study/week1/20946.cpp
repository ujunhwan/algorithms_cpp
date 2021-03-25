// https://www.acmicpc.net/problem/20946
// 20946번 합성인수분해

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef long long ll;

static const int bufSize = 1 << 20;

bitset <bufSize> prime;
ll n;

inline bool isPrime(int n) {
    if (n > 2 && n % 2 == 0) return false;
    return prime.test(n) ? false : true;
}

void solve() {
    prime.set(2);
    for(int i = 3; i <= 1000; i += 2)
        if(!prime.test(i))
            for(int j = i + i; j <= bufSize; j += i)
                prime.set(j);

    cin >> n;

    bool isComposite = false;
    for(int i = 2; i <= 1000001; i++) {
        // composite number
        if(n%i == 0) {
            if(n != i) isComposite = true;
            break;
        }
    }

    if(isComposite) {
        queue<ll> cand;
        ll num = 2;
        while(num < 1000001 && n > 1) {
            // divide
            while(n % num == 0) {
                n /= num;
                cand.push(num);
            }

            // next prime number
            while(!isPrime(++num) && num < 1000001);
        }

        if(n > 1) cand.push(n);

        while(!cand.empty()) {
            ll cand1 = cand.front(); cand.pop();
            ll cand2 = cand.front(); cand.pop();
            ll cand3 = 1;
            if(cand.size() == 1) {
                cand3 = cand.front();
                cand.pop();
            }
            // cout << cand1 << " " << cand2 << " " << cand3 << '\n';
            ll ans = cand1*cand2*cand3;
            cout << ans << " ";
        }
    } else {
        puts("-1");
    }
}

int main() {
    fastio;
    solve();
}