#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int G, H, counter;
vector<vector<int> >adj;
vector<int>visited;
vector<bool>dominated;
vector<int>cctv;

void initializer() {
    adj = vector<vector<int> >(G, vector<int>(G, 0));
    dominated = vector<bool>(G, false);
    visited = vector<int>(G, -1);
    cctv = vector<int>();
    counter = 1;
}

void dfs(int from, int here) {
    int possible = 0;
    vector<int>connected;
    visited[here] = counter++;
    for(int there = 0; there < adj.size(); there++) {
        if(adj[here][there] > 0 && visited[there] < 0) {
            possible++;
            connected.push_back(there);
            dfs(here, there);
        }
    }
    
    if(possible == 0) {
        // cout << "possible = 0 " << here << '\n';
        if(from == -1)
            cctv.push_back(here);
        return;
    }

    bool allDominated = true;
    for(int i = 0; i < connected.size(); i++) {
        if(!dominated[connected[i]]) {
            dominated[here] = true;
            dominated[connected[i]] = true;
            allDominated = false;
        }
    }

    if(allDominated) {
        if(from == -1 && !dominated[here])
            cctv.push_back(here);
        return;
    }

    if(dominated[here]) {
        if(from != -1)
            dominated[from] = true;
        cctv.push_back(here);
    }
    // cout << "all pass! : " << here << '\n';
}

int solve() {
    dfs(-1, 0);
    for(int i = 0; i < G; i++)
        if(visited[i] < 0) {
            // cout << "not visited : " << i << '\n';
            dfs(-1, i);
        }
    int ret = cctv.size();
    // for(int i = 0; i < cctv.size(); i++)
        // cout << cctv[i] << " ";
    // cout << '\n';
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int C; cin >> C;
    while(C--) {
        cin >> G >> H;
        initializer();
        for(int i = 0; i < H; i++) {
            int p, q; cin >> p >> q;
            adj[p][q] = 1;
            adj[q][p] = 1;
        }
        cout << solve() << '\n';
    }
    return 0;
}