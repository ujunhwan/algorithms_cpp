#include <bits/stdc++.h>
using namespace std;

int tc, h, w;
char board[25][25];

void solve() {
    
}

int main() {
    for(scanf("%d", &tc); tc--;) {
        scanf("%d %d", &h, &w);
        for(int i = 0; i < h; i++)
            scanf("%s", board[i]);
        
        solve();
    }

    return 0;
}