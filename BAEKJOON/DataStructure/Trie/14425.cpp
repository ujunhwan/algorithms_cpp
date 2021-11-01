// https://www.acmicpc.net/problem/14425
// 14425번 문자열 집합

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;
const int maxChild = 26;
const int base = 'a';

struct Trie {
    Trie* child[maxChild];
    bool isTerminal;

    Trie() {
        isTerminal = false;
        fill(child, child+maxChild, nullptr);
    }

    ~Trie() {
        for(auto node : child) {
            if(node) delete node;
        }
    }

    void insert(const char* key) {
        if(*key == '\0') {
            isTerminal = true;
        } else {
            int next = *key - base;
            if(!child[next]) {
                child[next] = new Trie();
            }
            child[next] -> insert(key+1);
        }
    }

    bool find(const char* key) {
        if(*key == '\0') return isTerminal;
        int next = *key - base;
        if(!child[next]) {
            return false;
        }
        return child[next] -> find(key+1);
    }
};

int N, M;

void solve() {
    cin >> N >> M;
    Trie* root = new Trie();
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        root -> insert(s.c_str());
    }
    int ans = 0;
    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        if(root -> find(s.c_str())) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    fastio;
    solve();
}