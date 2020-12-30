#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
map<int, int> coords;

bool isDominated(int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);
    if(it == coords.end()) return false;
    return y < it -> second;
}

void removeDominated(int x, int y) {
    // cout << "x, y : " << x << " " << y << '\n';
    map<int, int>::iterator it = coords.lower_bound(x);
    // cout << "it initial value : " << it -> first << " " << it -> second << '\n';
    if(it == coords.begin()) return;
    --it;
    // cout << "it second value : " << it -> first << " " << it -> second << '\n';
    while(true) {
        if(it -> second > y) 
            break;
        if(it == coords.begin()) {
            coords.erase(it);
            break;
        }
        else {
            coords.erase(it--);
        }
    }
    cout << "end" << '\n';
}

int registered(int x, int y) {
    if(isDominated(x, y)) return coords.size();
    removeDominated(x, y);
    coords.insert({x, y});
    return coords.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        coords.clear();

        cin >> n;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int p, q; cin >> p >> q;
            ans += registered(p, q);
        }

        cout << ans << '\n';
    }
    return 0;
}