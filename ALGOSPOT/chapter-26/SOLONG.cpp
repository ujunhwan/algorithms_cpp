#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

static const int ALPHABETS = 26;
static const int INF = 987654321;

bool compare(const pair<int, string>&a, const pair<int, string>&b) {
    if(a.first == b.first)
        return a.second.compare(b.second) < 0;
    return a.first > b.first;
    // 클수록 앞에위치
}

struct TrieNode {
    TrieNode* children[ALPHABETS];
    int terminal;
    int first;

    TrieNode() : terminal(false) {
        memset(children, 0, sizeof(children));
        terminal = -1;
        first = -1;
    }
    
    ~TrieNode() {
        for(int i = 0; i < ALPHABETS; i++)
            if(children[i])
                delete children[i];
    }

    // 먼저 들어올수록 우선순위 높음
    void insert(int id, const char *key) {
        if(first == -1) first = id;
        if(*key == 0) terminal = id;
        else {
            int next = *key - 'A';
            if(children[next] == NULL)
                children[next] = new TrieNode();
            children[next] -> insert(id, key + 1);
        }
    }

    TrieNode* find(const char* key) {
        if(*key == 0) return this;
        int next = *key - 'A';
        if(children[next] == NULL) return NULL;
        return children[next] -> find(key + 1);
    }

    int type(int id, const char *key) {
        if(*key == 0) return 0;
        if(first == id) return 1;
        int next = *key - 'A';
        return children[next] -> type(id, key + 1) + 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;

        vector<pair<int, string> >input;
        for(int i = 0; i < N; i++) {
            string word;
            int freq;
            cin >> word >> freq;
            input.push_back(make_pair(freq, word));
        }

        sort(input.begin(), input.end(), compare);
        
        TrieNode* trie = new TrieNode();
        for(int i = 0; i < input.size(); i++)
            trie -> insert(i, input[i].second.c_str());
        trie -> first = -1;

        int ans = M - 1;
        for(int i = 0; i < M; i++) {
            string word; cin >> word;
            TrieNode* node = trie -> find(word.c_str());
            if(node == NULL || node -> terminal == -1) ans += word.size();
            else ans += trie -> type(node -> terminal, word.c_str());
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
1
8 9
ALL 4
AND 3
FISH 8
FOR 6
SO 4
THANKS 9
THE 9
THA 9
SO LONG AND THANKS FOR ALL THE FISH THA
*/