#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;


int C, N, M;
int price[21], wish[21];
int c[200 + 1];

/*
int sushi(int last, int left) {
    if(left <= 0) return 0;
    int ret = 0;
    for(int i = last; i < N; i++) {
        if(left - price[i] >= 0)
            ret = max(ret, sushi(i, left - price[i]) + wish[i]);
    }
    return ret;
}
*/

int sushi() {
    int ret = 0;
    c[0] = 0;
    for(int budget = 1; budget <= M; budget++) {
        int cand = 0;
        for(int i = 0; i < N; i++) 
            if(budget >= price[i])
                cand = max(cand, c[(budget - price[i]) % 201] + wish[i]);
        c[budget % 201] = cand;
        ret = max(ret, cand);
    }
    return ret;
}

int main() {
    fastio;
    cin >> C;
    while(C--) {
        memset(c, 0, sizeof(c));
        memset(price, 0, sizeof(price));
        memset(wish, 0, sizeof(wish));
        cin >> N >> M;
        M /= 100;
        for(int i = 0; i < N; i++)
            cin >> price[i] >> wish[i];
        for(int i = 0; i < N; i++)
            price[i] /= 100;
        cout << sushi() << '\n';
    }
    return 0;
}