#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
const int M = 30;
const string CANNOT = "IMPOSSIBLE";
vector<string>words;
vector<string>edge[30][30];
vector<vector<int> >adj;
vector<int>indegree, outdegree;

void initializer() {
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            edge[i][j].clear();
    words = vector<string>(N + 1);
    adj = vector<vector<int> >(M, vector<int>(M, 0));
    indegree = vector<int>(M, 0);
    outdegree = vector<int>(M, 0);
}

void makeGraph() {
    for(int i = 0; i < N; i++) {
        int a = words[i][0] - 'a';
        int b = words[i][words[i].size() - 1] - 'a';
        edge[a][b].push_back(words[i]);
        adj[a][b]++;
        indegree[b]++; 
        outdegree[a]++;
    }
}

void getEulerCircuit(int here, vector<int>&circuit) {
    for(int there = 0; there < adj.size(); there++)
        while(adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    circuit.push_back(here);
}

vector<int> wordchain() {
    int start = -1;
    for(int i = 0; i < M; i++)
        if(outdegree[i] == indegree[i] + 1) {
            start = i;
            break;
    }

    vector<int>circuit;
    if(start >= 0)
        getEulerCircuit(start, circuit);
    else {
        for(int i = 0; i < M; i++)
            if(outdegree[i]) {
                getEulerCircuit(i, circuit);
                break;
            }
    }
    for(int i = 0; i < 27; i++) {
        for(int j = 0; j < 27; j++) {
            if(adj[i][j] > 0) {
                return vector<int>();
            }
        }
    }
    return circuit;
}

string solve() {
    makeGraph();
    vector<int>order = wordchain();
    reverse(order.begin(), order.end());
    if(order.empty()) 
        return CANNOT;

    string ret = "";
    for(int i = 1; i < order.size(); i++) {
        int a = order[i-1], b = order[i];
        ret += edge[a][b].back();
        ret += " ";
        edge[a][b].pop_back();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int C; cin >> C;
    while(C--) {
        cin >> N;
        initializer();
        for(int i = 0; i < N; i++)
            cin >> words[i];
        cout << solve() << '\n';
    }
    return 0;
}