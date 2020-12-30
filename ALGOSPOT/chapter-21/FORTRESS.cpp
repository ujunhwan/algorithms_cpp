#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef struct _node {
    vector<int>child;
} Node;

typedef struct _pos {
    int r, x, y;
} Pos;

int n, longest;
vector<Pos>castle;

bool cmp(const Pos&a, const Pos&b) {
    return a.r < b.r;
}

int distance(int i, int j) {
    return pow(castle[i].x - castle[j].x, 2) + pow((castle[i].y - castle[j].y), 2);
}

// i가 j에 포함되면 true!
bool judge(int i, int j) {
    return distance(i, j) < pow(castle[j].r, 2);
}

vector<Node> makeTree() {
    vector<Node>node(n);
    for(int i = 0; i < n ; i++) {
        for(int j = i + 1; j < n; j++) {
            if(castle[i].r >= castle[j].r) continue;
            // i << j
            if(judge(i, j)) {
                node[j].child.push_back(i);
                break;
            }
        }
    }
    return node;
}

void printNode(int index, vector<Node>&node) {
    int n = node[index].child.size();
    cout << index << '\n';
    for(int i = 0; i < n; i++) {
        printNode(node[index].child[i], node);
    }
}

int calcNode(int index, vector<Node>&node) {
    int m = node[index].child.size();
    if(m == 0) return 0;

    vector<int>cand;

    for(int i = 0; i < m; i++) {
        int child = calcNode(node[index].child[i], node) + 1;
        cand.push_back(child);
    }

    sort(cand.begin(), cand.end(), greater<int>());

    if(cand.size() >= 2)
        longest = max(longest, cand[0] + cand[1]);

    return cand[0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        Pos pos;
        castle.clear();
        longest = 0;

        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> pos.x >> pos.y >> pos.r;
            castle.push_back(pos);
        }

        sort(castle.begin(), castle.end(), cmp);

        vector<Node>node = makeTree();

        int height = calcNode(n - 1, node);

        if(height > longest) cout << height << '\n';
        else cout << longest << '\n';
    }
    return 0;
}