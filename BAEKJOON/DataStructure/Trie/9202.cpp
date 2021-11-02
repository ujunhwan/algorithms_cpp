// https://www.acmicpc.net/problem/9202
// 9202번 Boggle

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

static const int INF = 0x3f3f3f3f;

const int d8x[8] = {1, 1, 0, -1, -1, -1, 0, 1}, d8y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct SetCmp {
    // size 오름차순, size 같을 땐 사전순
    bool operator() (const string& a, const string& b) const {
        return (a.size() == b.size()) ? a < b : a.size() > b.size();
    }
};

vector<string> board;
set<string, SetCmp> res;
bool vst[4][4];

struct Trie {
    bool isTerminal;
    Trie* children[26];

    Trie() {
        isTerminal = false;
        fill(children, children+26, nullptr);
    }
    
    ~Trie() {
        for(auto child : children) {
            if(child) {
                delete child;
            }
        }
    }

    void insert(const char* key) {
        if(*key == '\0') {
            isTerminal = true;
        } else {
            if(children[*key-'A'] == NULL) {
                children[*key-'A'] = new Trie();
            }
            children[*key-'A']->insert(key+1);
        }
    }

    void find(int y, int x, string str) {
        if(str.size() >= 8) return;
        str += board[y][x];
        if(vst[y][x]) return;
        if(isTerminal) {
            res.insert(str);
        }
        vst[y][x] = true;
        for(int k = 0; k < 8; k++) {
            int ny = y+d8y[k], nx = x+d8x[k];
            if(ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
            Trie* childNode = children[board[ny][nx]-'A'];
            if(childNode == NULL) continue;
            childNode->find(ny, nx, str);
        }
        vst[y][x] = false;
    }
};

int w, b, score[9];

void solve() {
    memset(score, 0, sizeof(score));
    score[3] = score[4] = 1;
    score[5] = 2;
    score[6] = 3;
    score[7] = 5;
    score[8] = 11;

    cin >> w;
    vector<string> words;
    Trie* root = new Trie();
    for(int i = 0; i < w; i++) {
        string s; cin >> s;
        words.push_back(s);
        root->insert(s.c_str());
    }

    cin >> b;
    while(b--) {
        board.clear();
        res.clear();
        
        for(int i = 0; i < 4; i++) {
            string s; cin >> s;
            board.push_back(s);
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(root->children[board[i][j]-'A']) {
                    root->children[board[i][j]-'A']->find(i, j, "");
                }
            }
        }

        int ans = 0;
        for(set<string>::iterator it = res.begin(); it != res.end(); it++) {
            int size = (*it).size();
            ans += score[size];
        }

        cout << ans << " " << *res.begin() << " " << res.size() << '\n';
    }

    delete root;
}

signed main() {
    fastio;
    solve();
}
