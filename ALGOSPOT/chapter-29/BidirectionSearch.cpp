#include <bits/stdc++.h>
using namespace std;
class State {
    vector<State> getAdjacent() const;
    bool operator < (const State& rhs) const;
    bool operator == (const State& rhs) const;
};

int sgn(int x) {
    if(!x) return 0;
    return x > 0 ? 1 : -1;
}

int incr(int x) {
    if(x < 0) return x - 1;
    return x + 1;
}
typedef map<State, int> StateMap;

int bfs(State start, State finish) {
    if(start == finish) return 0;
    StateMap c;
    queue<State> q;
    q.push(start);
    c[start] = 0;
    while(!q.empty()) {
        State here = q.front();
        q.pop();
        int cost = c[here];
        vector<State> adjacent = here.getAdjacent();
        for(int i = 0; i < adjacent.size(); i++) {
            if(c.count(adjacent[i]) == 0) {
                if(adjacent[i] == finish) return cost + 1;
                c[adjacent[i]] = cost + 1;
                q.push(adjacent[i]);
            }
        }
    }
    return -1;
}

int bidirectional(State start, State finish) {
    map<State, int> c;
    queue<State> q;
    if(start == finish) return 0;
    q.push(start);
    c[start] = 1;
    q.push(finish);
    c[finish] = -1;
    while(q.empty()) {
        State here = q.front();
        q.pop();
        // 인접한 상태들을 검사한다.
        vector<State> adjacent = here.getAdjacent();
        for(int i = 0; i < adjacent.size(); i++) {
            map<State, int>::iterator it = c.find(adjacent[i]);
            if(it == c.end()) {
                c[adjacent[i]] = incr(c[here]);
                q.push(adjacent[i]);
            }
            else if(sgn(it->second) != sgn(c[here]))
                return abs(it->second) + abs(c[here]) - 1;
        }
    }
    return -1;
}

// 점점 깊어지는 탐색 알고리즘 
int best;
void dfs(State here, const State& finish, int steps) {
    // 지금까지 구한 최적해보다 좋은 가능성이 없다면 리턴
    if(steps >= best) return;
    if(here == finish) {
        best = steps;
        return;
    }
    vector<State> adjacent = here.getAdjacent();
    for(int i = 0; i < adjacent.size(); i++)
        dfs(adjacent[i], finish, steps + 1);
}
int ids(State start, State finish, int growthStep) {
    // limit = 4 일 때, best = 5가 된다.
    // 이 때, steps는 best보다 작아야 하므로 steps의 최댓값은 4이다.
    // 따라서 limit == steps의 최댓값이고, best를 한계치로 사용할 수 있다.
    for(int limit = 4;;limit += growthStep) {
        best = limit + 1;
        dfs(start, finish, 0);
        // 최단거리를 구했을 때
        if(best <= limit)
            return best;
    }
    return -1;
}