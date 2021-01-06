#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
// 모르겠어~~!!!!

static const int ALPHABETS = 26;
static const int MOD = 10007;

int toNumber(char ch) {
    return ch - 'a';
}

struct TrieNode {
    int terminal;
    int no;
    TrieNode* children[ALPHABETS];
    TrieNode* fail;
    vector<int> output;

    TrieNode() {
        memset(children, 0, sizeof(children));
        terminal = -1;
        no = -1;
    }

    void insert(const char* key, int id) {
        if(*key == 0)
            terminal = id;
        else {
            int next = *key - 'A';
            if(children[next] == NULL)
                children[next] = new TrieNode();
            return children[next] -> insert(key + 1, id);
        }
    }

    TrieNode* find(const char *key) {
        if(*key == 0) return this;
        int next = *key - 'A';
        if(children[next] == NULL) return NULL;
        return children[next] -> find(key + 1);
    }
};

void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    root -> fail = root;
    q.push(root);
    while(!q.empty()) {
        TrieNode* here = q.front();
        q.pop();
        for(int edge = 0; edge < ALPHABETS; edge++) {
            TrieNode* child = here -> children[edge];
            if(!child) continue;
            if(here == root)
                child -> fail = root;
            else {
                TrieNode* t = here -> fail;
                while(t != root && t -> children[edge] == NULL)
                    t = t -> fail;
                if(t -> children[edge]) t = t -> children[edge];
                child -> fail = t;
            }
            child -> output = child -> fail -> output;
            if(child -> terminal != -1)
                child -> output.push_back(child -> terminal);
            q.push(child);
        }
    }
}

vector<pair<int, int> > ahoCorasick(const string& s, TrieNode* root) {
    vector<pair<int, int> > ret;
    TrieNode* state = root;
    for(int i = 0; i < s.size(); i++) {
        int chr = toNumber(s[i]);
        while(state != root && state -> children[chr] == NULL)
            state = state -> fail;
        if(state -> children[chr])
            state = state -> children[chr];
        for(int j = 0; j < state -> output.size(); j++)
            ret.push_back(make_pair(i, state -> output[j]));
    }
    return ret;
}

// a ^ N % MOD
int fastModExp(int a, int N) {
    int ret = 1;
    if(N & 1) ret = 26;
    while(N) {
        N = N >> 1;
        a = a * a % MOD;
        if(N & 1) ret = (ret * a) % MOD;
    }
    return ret;
}

int countMatched(int length, TrieNode* state) {
    if(state -> output.size()) return 0;
    if(length == 0) return 1;
    int& ret = cache[length][state -> no];

}

int main() {
    int C; cin >> C;
    while(C--) {
        int N, M; cin >> N >> M;
        vector<int>pattern(M);
        for(int i = 0; i < M; i++)
            cin >> pattern[i];
        // IDS에 인식되지 않는 문자열 수
        int total = fastModExp(26, N);
        cout << total << '\n';
    }
    return 0;
}