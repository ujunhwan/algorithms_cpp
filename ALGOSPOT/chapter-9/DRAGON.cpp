#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000000 + 1;
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

int tc, n, p, l;
int length[51];

void precalc() {
    length[0] = 1;
    for(int i = 1; i <= 50; i++)
        length[i] = min(INF, length[i - 1] * 2 + 2);
}

char expand(const string& dragonCurve, int generations, int skip) {
    if(generations == 0) return dragonCurve[skip];
    for(int i = 0; i < dragonCurve.size(); i++) {
        if(dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
            if(skip >= length[generations]) skip -= length[generations];
            else if(dragonCurve[i] == 'X') return expand(EXPAND_X, generations - 1, skip);
            else return expand(EXPAND_Y, generations - 1, skip);
        } else if(skip > 0) skip -= 1;
        else return dragonCurve[i];
    }
    return '#';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    precalc();
    cin >> tc;
    while(tc--) {
        cin >> n >> p >> l;
        int skip = p - 1;
        for(int i = 0; i < l; i++)
            cout << expand("FX", n, skip + i);
        cout << '\n';
    }
    return 0;
}