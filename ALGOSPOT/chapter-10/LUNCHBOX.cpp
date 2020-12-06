#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int C, N;
vector<int>m, e;

bool compare(const pair<int, int>&a, const pair<int, int>&b) {
    return a.first > b.first;
}

int order() {
    int ret = 0, beginEat = 0;
    vector<pair<int, int> >pii;
    for(int i = 0; i < N; i++)
        pii.push_back(make_pair(e[i], m[i]));
    sort(pii.begin(), pii.end(), compare);
    for(int i = 0; i < N; i++) {
        beginEat += pii[i].second;
        int cand = pii[i].first + beginEat;
        ret = max(ret, cand);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> C;
    while(C--) {
        m.clear(), e.clear();
        cin >> N;
        int tmp;
        for(int i = 0; i < N; i++) {
            cin >> tmp;
            m.push_back(tmp);
        }
        for(int i = 0; i < N; i++) {
            cin >> tmp;
            e.push_back(tmp);
        }
        cout << order() << '\n';
    }
}