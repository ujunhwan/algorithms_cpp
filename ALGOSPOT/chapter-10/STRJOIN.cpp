#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int C, N;
priority_queue<int, vector<int>, greater<int>> pq;

int greedy() {
    int ret = 0;
    while(pq.size() > 1) {
        int m1 = pq.top(); pq.pop();
        int m2 = pq.top(); pq.pop();
        pq.push(m1 + m2);
        ret += m1 + m2;
    }
    pq.pop();
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> C;
    while(C--) {
        cin >> N;
        int tmp;
        for(int i = 0; i < N; i++) {
            cin >> tmp;
            pq.push(tmp);
        }
        cout << greedy() << '\n';
    }
    return 0;
}