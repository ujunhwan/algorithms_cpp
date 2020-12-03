#include <iostream>
#include <vector>
using namespace std;
void pick(int n, vector<int>&picked, int toPick) {
    if (toPick == 0) {
        printPicked(picked);
        return;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;  // 가장 작은 수
    for(int next = smallest; next < n; ++next) {    // 가장 작은수부터 ~~~
        picked.push_back(next);
        pick(n, picked, toPick - 1);
                                                        // 1234 / 1235 / 1236 / 1237
                                                        // 1245 / 1246 / 1247
                                                        // 1256 / 1257
                                                        // 1267
        picked.pop_back();
    }
}