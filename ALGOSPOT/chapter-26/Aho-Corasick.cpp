#include <bits/stdc++.h>
using namespace std;

const int ALPHABETS = 26;

int toNumber(char ch) {
    return ch - 'A';
}

struct TrieNode {
    TrieNode* children[ALPHABETS];
    // 현 위치에서 끝나는 문자열 번호
    int terminal;
    // 이 노드에 대응되는 문자열이 접미사면서 트라이에 포함된 최대 문자열
    TrieNode* fail;
    // 출력 문자열 목록 : 이 노드가 방문되었을 때 등장하는 바늘 문자열들의 번호
    vector<int> output;
    TrieNode() : terminal(false) {
        memset(children, 0, sizeof(children));
        terminal = -1;
    }
    ~TrieNode() {
        for(int i = 0; i < ALPHABETS; i++)
            if(children[i])
                delete children[i];
    }

    void insert(const char* key) {
        if(*key == 0) {
            terminal = true;
        }
        else {
            int next = toNumber(*key);
            if(children[next] == NULL)
                children[next] = new TrieNode();
            children[next] -> insert(key + 1);
        }
    }

    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        int next = toNumber(*key);
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
        if(state -> children[chr]) state = state -> children[chr];
        for(int j = 0; j < state -> output.size(); j++)
            ret.push_back(make_pair(i, state -> output[j]));
    }
    return ret;
}

int main() {
    return 0;
}