#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int C, K;
const int INF = 987654321;
int overlap[16][16];
int cache[16][(1 << 15) + 1];
string word[15];

void precalc() {
    memset(overlap, 0, sizeof(overlap));
    memset(cache, -1, sizeof(cache));

    // 포함시 삭제
    while(true) {
        bool removed = false;
        for(int i = 0; i < K; i++)
            for(int j = 0; j < K; j++) {
                if(i == j) continue;
                string left = word[i], right = word[j];
                if(left.find(right) != -1) { // 포함 된다면
                    word[j] = word[K - 1];
                    K--;
                    removed = true;
                }
            }
        if(!removed) break;
    }

    word[K] = "";

    // 오버랩 계산 
    for(int i = 0; i <= K; i++)
        for(int j = 0; j <= K; j++) {
            string left = word[i], right = word[j];
            int in = left.size(), jn = right.size(), index = 0;
            for(int len = min(in, jn); len > 0; len--)
                if(left.substr(in - len) == right.substr(0, len)) {
                    overlap[i][j] = len;
                    break;
                }
        }
        
    return;
}

int restore(int last, int used) {
    if(used == ((1 << K) - 1)) return 0;
    int& ret = cache[last][used];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = 0; next < K; next++) {
        if((used & (1 << next)) == 0) {
            int cand = overlap[last][next] + restore(next, used + (1 << next));
            ret = max(ret, cand);
        }
    }
    return ret;
}

string reconstruct(int last, int used) {
    if(used == ((1 << K) - 1)) return "";
    for(int next = 0; next < K; next++) {
        if(used & (1 << next)) continue;
        int cand = overlap[last][next] + restore(next, used + (1 << next));
        if(cand == restore(last, used)) {
            string result = reconstruct(next, used + (1 << next));
            string ret =  word[next].substr(overlap[last][next]) + result;
            return ret;
        }
    }
    return "error";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> C;
    while(C--) {
        cin >> K;
        for(int i = 0; i < K; i++)
            cin >> word[i];
        precalc();
        word[K] = "";
        cout << reconstruct(K, 0) << '\n';
    }
    return 0;
}