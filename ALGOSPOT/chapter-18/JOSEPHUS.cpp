#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

void josephus(int n, int k) {
    vector<int> ret(n + 1);
    for(int i = 0; i <= n; i++)
        ret[i] = i;
    ret.erase(ret.begin());

    int kill = 0;
    while(ret.size() > 2) {
        ret.erase(ret.begin() + kill);
        kill += (k - 1);
        if(kill >= ret.size()) kill %= ret.size();
    }

    for(int i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    while(tc--) {
        int n, k; cin >> n >> k;
        josephus(n, k);
    }
    return 0;
}