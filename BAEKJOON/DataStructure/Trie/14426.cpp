// https://www.acmicpc.net/problem/14426
// 14426번 접두사 찾기

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

struct Trie {
    bool isTerminal;
    Trie* next[26];

    Trie() {
        isTerminal = false;
        fill(next, next+26, nullptr);
    }

    ~Trie() {
        for(auto node : next) {
            if(node) delete node;
        }
    }

    void insert(const char* key) {
        if(*key == '\0') {
            isTerminal = true;
        } else {
            if(next[*key-'a'] == NULL) {
                next[*key-'a'] = new Trie();
            }
            next[*key-'a']->insert(key+1);
        }
    }

    bool query(const char* key) {
        if(*key == '\0') return true;
        if(next[*key-'a']) return next[*key-'a']->query(key+1);
        else return false;
    }
};

int N, M;

void solve() {
    cin >> N >> M;
    Trie* root = new Trie();
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        root->insert(s.c_str());
    }

    int ans = 0;
    while(M--) {
        string s; cin >> s;
        if(root->query(s.c_str())) ans++;
    }
    cout << ans << '\n';
}


signed main() {
    fastio;
    solve();
}

/*
5 10
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh

baekjoon *
star *
start *
code *
sunday *
coding *
cod *
online 
judge
plus
*/