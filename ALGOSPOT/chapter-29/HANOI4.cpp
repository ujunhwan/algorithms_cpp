#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

int tc, n;
int c[(1<<(12*2))+1];

int get(int index, int state) {
    return (state >> (index * 2)) & 3;
}

int set(int index, int state, int value) {
    return (state & ~(3 << (index * 2))) | (value << (index * 2));
}

int incr(int a) {
    if(a == 0)
        return 0;
    return a > 0 ? a + 1 : a - 1;
}

int bidirectionSearch(int init, int goal) {
    queue<int> q;
    c[init] = 1;
    c[goal] = -1;
    q.push(init);
    q.push(goal);
    while(!q.empty()) {
        int here = q.front();
        q.pop();

        int top[4] = {-1, -1, -1, -1};
        for(int i = n - 1; i >= 0; i--)
            top[get(i, here)] = i;
        
        for(int i = 0; i < 4; i++)
            if(top[i] != -1)
                for(int j = 0; j < 4; j++)
                    if(i != j && (top[i] < top[j] || top[j] == -1)) {
                        int there = set(top[i], here, j);
                        if(c[there] == 0) {
                            c[there] = incr(c[here]);
                            q.push(there);
                        }
                        else if(c[there] * c[here] < 0)
                            return abs(c[there]) + abs(c[here]) - 1;
                    }
    }
    return 0;
}

int solve(int init, int goal) {
    memset(c, 0, sizeof(c));
    if(init == goal) return 0;
    return bidirectionSearch(init, goal);
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        scanf("%d", &n);
        int init = 0, goal = pow(2, n * 2) - 1;
        for(int i = 0; i < 4; i++) {
            int num, val;
            scanf("%d", &num);
            for(int j = 0; j < num; j++) {
                scanf("%d", &val);
                init |= i << ((val - 1) * 2);
            }
        }

        printf("%d\n", solve(init, goal));
    }
    return 0;
}