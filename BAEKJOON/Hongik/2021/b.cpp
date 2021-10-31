#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

void solve() {
    vector<string> a;
    int size = 0;
    int b[10001];
    for(int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        size = str.size();
        a.push_back(str);
    }

    // 0 ready 1 ing 2 done
    for(int i = 0; i < size; i++) {
        if(a[1][i] == 'o') b[i] = 1;
        else if(a[1][i] == 'w') b[i] = 0;
        else if(a[1][i] == '.') b[i] = 2;
    }

    vector<string> c;
    c.push_back(".o.");
    c.push_back("ow.");
    c.push_back("mlo");
    c.push_back("lnL");
    c.push_back("n.n");

    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < size; i++) {
            if(b[i] == 0) cout << c[j][0];
            else if(b[i] == 1) cout << c[j][1];
            else cout << c[j][2];
        }
        cout << '\n';
    }
    
}

signed main() {
    fastio;
    solve();
}