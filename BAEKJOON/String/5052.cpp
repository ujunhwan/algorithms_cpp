// https://www.acmicpc.net/problem/5052
// 5052번 전화번호 목록

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int NUM = 10;

struct TrieNode {
    TrieNode* children[NUM];
    bool childExist;
    bool terminal;

    TrieNode() {
        fill(children, children + NUM, nullptr);
        terminal = false;
        childExist = false;
    }

    ~TrieNode() {
        for(int i = 0; i < NUM; i++)
            if(children[i])
                delete children[i];
    }

    void insert(const char* key) {
        if(*key == '\0') {
            terminal = true;
        } else {
            int next = *key - '0';
            if(!children[next])
                children[next] = new TrieNode;
            childExist = true;
            children[next] -> insert(key + 1);
        }
    }

    bool isConsistent() {
        if(terminal && childExist) return false;
        for(int i = 0; i < NUM; i++)
            if(children[i] && children[i] -> isConsistent() == false) return false;
        return true;
    }
};


void solve() {
    int tc; cin >> tc;
    while(tc--) {
        TrieNode *root = new TrieNode;

        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            char str[11]; cin >> str;
            root -> insert(str);
        }

        puts(root -> isConsistent() ? "YES" : "NO");

        delete root;
    }
}

int main() {
    fastio;
    solve();
}