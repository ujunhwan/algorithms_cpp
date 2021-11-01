// https://www.acmicpc.net/problem/14725
// 14725번 개미굴

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

struct Trie {
    map<string, Trie*> child;

    void insert(int idx, vector<string>& key) {
        if(idx == key.size()) return;
        map<string, Trie*>::iterator it = child.find(key[idx]);
        if(it == child.end()) {
            Trie* node = new Trie();
            it = child.insert({key[idx], node}).first;
        }
        Trie* childNode = it->second;
        childNode->insert(++idx, key);
    }

    void traverse(string pre) {
        for(auto next : child) {
            string str = pre+next.first;
            Trie* childNode = next.second;
            cout << str << '\n';
            childNode -> traverse(pre+"--");
        }
    }
};

int N;

void solve() {
    cin >> N;
    set<string> s;
    map<string, int> m;
    Trie* root = new Trie();
    int idx = 0;
    for(int i = 0; i < N; i++) {
        int K;
        cin >> K;
        vector<string> v;
        for(int j = 0; j < K; j++) {
            string str;
            cin >> str;
            v.push_back(str);
        }
        root->insert(0, v);
    }

    root->traverse("");
}

signed main() {
    fastio;
    solve();
}