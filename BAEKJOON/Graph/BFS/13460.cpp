// https://www.acmicpc.net/problem/13460
// 13460번 구슬 탈출 2

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// right down left up 
const int d4x[4] = {1, 0, -1, 0}, d4y[4] = {0, -1, 0, 1};

int n, m;
vector<string> a;
int cost[200][200];

bool bfs(int rinit, int binit, int hole) {
    // red, blue
    memset(cost, 0x7f, sizeof(cost));
    queue<pair<int, int> > q;
    q.push(make_pair(rinit, binit));
    cost[rinit][binit] = 0;

    while(!q.empty()) {
        int rd = q.front().first, bd = q.front().second;
        int ry = rd/m, rx = rd%m;
        int by = bd/m, bx = bd%m;
        int hereCost = cost[rd][bd];
        q.pop();

        if(hereCost > 10 && hereCost != 0x7f7f7f7f) return false;
        for(int k = 0; k < 4; k++) {
            bool blueMeet = false, redMeet = false;
            bool redHole = false, blueHole = false;
            int rny = ry, rnx = rx;
            int bny = by, bnx = bx;

            while(1) {
                if(a[rny + d4y[k]][rnx + d4x[k]] == '#') break;
                else if(rny + d4y[k] == by && rnx + d4x[k] == bx) {
                    blueMeet = true;
                    break;
                }
                else if(a[rny + d4y[k]][rnx + d4x[k]] == 'O') {
                    redHole = true;
                }
                rny += d4y[k], rnx += d4x[k];
            }

            // blue
            while(1) {
                if(a[bny + d4y[k]][bnx + d4x[k]] == '#') break;
                else if(bny + d4y[k] == ry && bnx + d4x[k] == rx) {
                    redMeet = true;
                    break;
                }
                else if(a[bny + d4y[k]][bnx + d4x[k]] == 'O') {
                    blueHole = true;
                }
                bny += d4y[k], bnx += d4x[k];
            }

            // red reposition
            if(blueMeet) {
                rny = bny - d4y[k], rnx = bnx - d4x[k];
                if(a[rny][rnx] == 'O') redHole = true;
            }

            // blue reposition
            if(redMeet) {
                // redMeet && redHole -> blueHole!
                if(redHole) blueHole = true;
                bny = rny - d4y[k], bnx = rnx - d4x[k];
                if(a[bny][bnx] == 'O') blueHole = true;
            }

            if(redHole && !blueHole) {
                cost[hole][0]= hereCost + 1;
                return true;
            }

            // blueHole -> don't care
            if(!blueHole && cost[rny*m+rnx][bny*m+bnx] > hereCost + 1) {
                cost[rny*m+rnx][bny*m+bnx] = hereCost + 1;
                q.push(make_pair(rny*m+rnx, bny*m+bnx));
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    a = vector<string>(n);
    int rinit, binit, hole;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] == 'R') rinit = i*m+j;
            else if(a[i][j] == 'B') binit = i*m+j; 
            else if(a[i][j] == 'O') hole = i*m+j;
        }
    }

    cout << (bfs(rinit, binit, hole) && cost[hole][0] <= 10 ? cost[hole][0] : -1) << '\n';
}

int main() {
    fastio;
    solve();
}