#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const string CANNOT = "IMPOSSIBLE";
string digits;
int N, M;
vector<int>num;

bool judge(int C) {
    return (C - M) % N == 0;
}

int append(int now, int edge) {
    int next = now * 10 + edge;
    if(next >= N) return N + next % N;
    return next % N;
}

string bfs(int start) {
    vector<int> parent(2 * N, -1), choice(2 * N, -1);
    queue<int>q;
    q.push(start);
    parent[0] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < num.size(); i++) {
            int next = append(now, digits[i] - '0');
            if(parent[next] == -1) {
                parent[next] = now;
                choice[next] = digits[i] - '0';
                q.push(next);
            }
        }
    }
    if(parent[N + M] == -1) return CANNOT;
    string ret;
    int here = N + M;
    while(parent[here] != here) {
        ret += char('0' + choice[here]);
        here = parent[here];
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string solve() {
    sort(digits.begin(), digits.end());
    return bfs(0);
}

int main() {
    int tc;
    for(scanf("%d", &tc); tc--;) {
        char tmp[100];
        scanf("%s %d %d", tmp, &N, &M);
        digits = tmp;
        printf("%d\n", solve());
    }
    return 0;
}