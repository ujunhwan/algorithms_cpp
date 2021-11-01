// https://www.acmicpc.net/problem/5670
// 5670번 휴대폰 자판

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

static const int INF = 0x3f3f3f3f;

using namespace std;

const int maxChildren = 27;

struct Trie {
    bool isTerminal;
    bool isRoot;
    Trie* children[maxChildren];
    int numOfChild;

    Trie() {
        isTerminal = isRoot = false;
        numOfChild = 0;
        fill(children, children+maxChildren, nullptr);
    }

    ~Trie() {
        for(auto child : children) {
            if(child) delete child;
        }
    }

    void insert(const char* key) {
        if(*key == '\0') {
            isTerminal = true;
        } else {
            if(!children[*key-'a']) {
                children[*key-'a'] = new Trie();
                numOfChild += 1;
            }
            children[*key-'a'] -> insert(key+1);
        }
    }

    int find(const char* key) {
        if(*key == '\0') return 0;
        if(isRoot) {
            return children[*key-'a']->find(key+1)+1;
        } else if(numOfChild > 1 || isTerminal) {
            return children[*key-'a']->find(key+1)+1;
        } else {
            return children[*key-'a']->find(key+1);
        }
    }
};

int N;

void solve() {
    vector<string> str;
    Trie* root = new Trie();
    root->isRoot = true;
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        root->insert(s.c_str());
        str.push_back(s);
    }

    double sum = 0;
    for(auto s : str) {
        sum += root->find(s.c_str());
    }

    delete root;

    double ans = sum / (double)str.size();
    cout << ans << '\n';
}

signed main() {
    fastio;
    precision(2);
    while(cin >> N) {
        solve();
    }
}