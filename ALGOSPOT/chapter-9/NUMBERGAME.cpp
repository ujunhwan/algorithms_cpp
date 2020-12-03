#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 987654321;
int C, N;
int numbers[50 + 1];
int cache[51][51];

void precalc() {
    for(int i = 0; i < 51; i++)
        for(int j = 0; j < 51; j++)
            cache[i][j] = -INF;
}

int numbergame(int left, int right) {
    if(left > right) return 0;
    int&ret = cache[left][right];
    if(ret != -INF) return ret;
    ret =  max(numbers[left] - numbergame(left + 1, right), numbers[right] - numbergame(left, right - 1));
    if(right - left + 1 >= 2) {
        ret = max(ret, -numbergame(left + 2, right));
        ret = max(ret, -numbergame(left, right - 2));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> C;
    while(C--) {
        precalc();
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> numbers[i];
        cout << numbergame(0, N - 1) << '\n';
    }
    return 0;
}