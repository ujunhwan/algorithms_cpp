// https://www.acmicpc.net/problem/12100
// 12100번 2048 (Easy)

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

static const int INF = 0x7f7f7f7f;

ll N, ans;

void moving(int direction, int count, vector<vector<ll> > board) {
    bool comb[22][22];
    memset(comb, false, sizeof(comb));
    if(count == 5) return;

    if(direction == 1) {
        for(int j = N-1; j >= 0; j--) {
            for(int i = 0; i < N; i++) {
                if(board[i][j] == 0) continue;
                ll val = board[i][j];
                ans = max(ans, val);
                board[i][j] = 0;
                int xPos = j, yPos = i;

                while(xPos < N-1 && board[yPos][xPos+1] == 0) {
                    xPos++;
                }

                if(xPos < N-1 && board[yPos][xPos+1] == val && !comb[yPos][xPos+1]) {
                    comb[yPos][xPos+1] = true;
                    board[yPos][xPos+1] = val*2;
                    ans = max(ans, val*2);
                } else {
                    board[yPos][xPos] = val;
                    ans = max(ans, val);
                }
            }
        }
    } else if(direction == 2) {
        for(int j = 0; j < N; j++) {
            for(int i = 0; i < N; i++) {
               if(board[i][j] == 0) continue;
                ll val = board[i][j];
                board[i][j] = 0;
                int xPos = j, yPos = i; 

                while(xPos > 0 && board[yPos][xPos-1] == 0) {
                    xPos--;
                }

                if(xPos > 0 && board[yPos][xPos-1] == val && !comb[yPos][xPos-1]) {
                    comb[yPos][xPos-1] = true;
                    board[yPos][xPos-1] = val*2;
                    ans = max(ans, val*2);
                } else {
                    board[yPos][xPos] = val;
                    ans = max(ans, val);
                }
            }
        }
    } else if(direction == 3) {
        for(int i = N-1; i >= 0; i--) {
            for(int j = 0; j < N; j++) {
              if(board[i][j] == 0) continue;
                ll val = board[i][j];
                board[i][j] = 0;
                int xPos = j, yPos = i; 

                while(yPos < N-1 && board[yPos+1][xPos] == 0) {
                    yPos++;
                }

                if(yPos < N-1 && board[yPos+1][xPos] == val && !comb[yPos+1][xPos]) {
                    comb[yPos+1][xPos] = true;
                    board[yPos+1][xPos] = val*2;
                    ans = max(ans, val*2);
                } else {
                    board[yPos][xPos] = val;
                    ans = max(ans, val);
                } 
            }
        }

    } else if(direction == 4) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == 0) continue;
                ll val = board[i][j];
                board[i][j] = 0;
                int xPos = j, yPos = i; 

                while(yPos > 0 && board[yPos-1][xPos] == 0) {
                    yPos--;
                }

                if(yPos > 0 && board[yPos-1][xPos] == val && !comb[yPos-1][xPos]) {
                    comb[yPos-1][xPos] = true;
                    board[yPos-1][xPos] = val*2;
                    ans = max(ans, val*2);
                } else {
                    board[yPos][xPos] = val;
                    ans = max(ans, val);
                }
            }
        }
    }

    // cout << "#####" << '\n';
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << "#####" << '\n';

    // moving(direction+1, count+1, board);

    for(int d = 1; d <= 4; d++) {
        moving(d, count+1, board);
    }
}

void solve() {
    cin >> N;
    vector<vector<ll> > board(N+1, vector<ll> (N+1, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    ans = 0;

    for(int d = 1; d <= 4; d++) {
        moving(d, 0, board);
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}

/**
 * 
4
4 4 2 2
0 0 0 0
0 0 0 0
0 0 0 0

4
2 4 16 8
8 4 0 0
16 8 2 0
2 8 2 0

*/