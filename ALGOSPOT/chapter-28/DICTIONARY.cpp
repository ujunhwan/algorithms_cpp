#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int ALPHABETS = 26;
const string CONTRADICTION = "INVALID HYPOTHESIS";

vector<vector<int> >adj;
vector<int>visited, order, finish;

int N, cycle;

void dfs(int here) {
    visited[here] = 1;
    for(int there = 0; there < adj.size(); there++)
        if(adj[here][there]) {
            if(!visited[there])
                dfs(there);
            else if(!finish[there])
                cycle = 1;
        }
    order.push_back(here);
    finish[here] = 1;
}

void topologicalSort() {
    for(int i = 0; i < adj.size(); i++)
        if(!visited[i])
            dfs(i);
    reverse(order.begin(), order.end());
}

void initializer() {
    cycle = 0;
    order.clear();
    adj.clear();
    visited.clear();
    finish.clear();
    adj = vector<vector<int> >(ALPHABETS, vector<int>(ALPHABETS, 0));
    visited = vector<int>(ALPHABETS, 0);
    finish = vector<int>(ALPHABETS, 0);
}

int main() {
    int C; cin >> C;
    while(C--) {
        cin >> N;
        initializer();
        vector<string>words(N);
        for(int i = 0; i < N; i++)
            cin >> words[i];

        for(int i = 0; i < N - 1; i++) {
            int len = min(words[i].size(), words[i+1].size());
            for(int j = 0; j < len; j++) {
                if(words[i][j] != words[i+1][j]) {
                    int a = words[i][j] - 'a';
                    int b = words[i+1][j] - 'a';
                    adj[a][b] = 1;
                    break;
                }
            }
        }

        topologicalSort();

        if(cycle > 0)
            cout << CONTRADICTION;
        else {
            for(int i = 0; i < order.size(); i++)
                cout << (char)(order[i] + 'a');
        }
        cout << '\n';
    }
    return 0;
}