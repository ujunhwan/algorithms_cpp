#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int>sequence;
map<vector<int>, int>space;
int N;

void precalc() {
    for(int n = 1; n <= 8; n++) {
        vector<int>permutation(n);
        for(int i = 0; i < n; i++)
            permutation[i] = i;
        queue<vector<int> >q;
        space[permutation] = 0;
        q.push(permutation);
        while(!q.empty()) {
            vector<int>here = q.front();
            q.pop();
            int cost = space[here];
            for(int i = 0; i < n; i++) {
                for(int j = i + 2; j <= n; j++) {
                    reverse(here.begin() + i, here.begin() + j);
                    vector<int>there = here;
                    reverse(here.begin() + i, here.begin() + j);
                    if(space.count(there) == 0) {
                        q.push(there);
                        space[there] = cost + 1;
                    }
                }
            }
        }
    }
    return;
}

void initializer() {
    sequence = vector<int>(N, 0);
}

int solve() {
    vector<int>transform(N, 0);
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(sequence[i] > sequence[j]) cnt++;
        }
        transform[i] = cnt;
    }
    return space[transform];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    precalc();
    int C; cin >> C;
    while(C--) {
        cin >> N;
        initializer();
        for(int i = 0; i < N; i++)
            cin >> sequence[i];
        cout << solve() << '\n';
    }
    return 0;
}