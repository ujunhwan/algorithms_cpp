// https://www.acmicpc.net/problem/13505
// 13505번 두 수 XOR

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

struct Trie {
    bool isTerminal;
    Trie* next[2];
    
    Trie() {
        isTerminal = false;
        fill(next, next+2, nullptr);
    }

    ~Trie() {
        for(auto node : next) {
            if(node) delete node;
        }
    }

    void insert(const char* key) {
        if(*key == '\0') {
            isTerminal = true;
            return;
        }
        Trie* nextNode = next[*key-'0'];
        if(!next[*key-'0']) {
            next[*key-'0'] = new Trie();
        }
        next[*key-'0']->insert(key+1);
    }

    string query(int idx, string a) {
        if(a[idx] == '\0') return "";
        int cur = a[idx]-'0';
        string ret = "";
        if(cur & 1) {
            if(!next[0]) 
                return next[1]->query(idx+1, a)+'1';
            return next[0]->query(idx+1, a)+'0';
        } else {
            if(!next[1])
                return next[0]->query(idx+1, a)+'0';
            return next[1]->query(idx+1, a)+'1';
        }
        return ret;
    }
};

int N;
vector<string> v;

int rconverter(string a) {
    int size = a.size()-1;
    int digit = 1;
    int ret = 0;
    for(int i = size; i >= 0; i--) {
        ret += digit*(a[i]-'0');
        digit *= 2;
    }
    return ret;
}
int converter(string a) {
    int size = a.size()-1;
    int digit = 1;
    int ret = 0;
    for(int i = 0; i < a.size(); i++) {
        ret += digit*(a[i]-'0');
        digit *= 2;
    }
    return ret;
}

void solve() {
    cin >> N;
    Trie* root = new Trie();
    for(int i = 0; i < N; i++) {
        int q;
        cin >> q;
        string str = "";
        for(int j = 31; j >= 0; j--) {
            if(q & (1 << j)) {
                str += '1';
            } else {
                str += '0';
            }
        }
        root->insert(str.c_str());
        v.push_back(str);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int a = converter(root->query(0, v[i]));
        // reverse(v[i].begin(), v[i].end());
        int b = rconverter(v[i]);
        ans = max(ans, a^b);
    }
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
}