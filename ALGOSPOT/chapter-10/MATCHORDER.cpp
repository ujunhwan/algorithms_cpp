#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 987654321;
int C, N;
vector<int> rus, kor;

int order() {
    sort(rus.begin(), rus.end());
    sort(kor.begin(), kor.end());
    int ret = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < kor.size(); j++)
            if(kor[j] >= rus[i]) {
                kor.erase(kor.begin() + j);
                ret++;
                break;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> C;
    while(C--) {
        rus.clear();
        kor.clear();
        cin >> N;
        int tmp;
        for(int i = 0; i < N; i++) {
            cin >> tmp;
            rus.push_back(tmp);
        }

        for(int i = 0; i < N; i++) {
            cin >> tmp;
            kor.push_back(tmp);
        }
        cout << order() << '\n';
    }
    return 0;
}