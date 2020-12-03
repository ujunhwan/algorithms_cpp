#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 3;
int cache[20000];

bool isFinished(char board[][3], char turn) {
    if(turn == board[0][0] && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if(turn == board[0][2] && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    for(int i = 0; i < MAX_N; i++)
        if(turn == board[i][0] && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    for(int j = 0; j < MAX_N; j++)
        if(turn == board[0][j] && board[0][j] == board[1][j] && board[1][j] == board[2][j]) return true;
    return false;
}

int bijection(char board[][3]) {
    int ret = 0;
    int weight = 1;
    for(int i = MAX_N - 1; i >= 0; i--) {
        for(int j = MAX_N - 1; j >= 0; j--) {
            int val = 0;
            if(board[i][j] == 'x') val = 1;
            if(board[i][j] == 'o') val = 2;
            ret += val * weight;
            weight *= 3;
        }
    }
    return ret;
}

int canWin(char board[][3], char turn) {
    // o를 놓을차롄데, x로 만들어졌으면 진거니까 -1반환
    if(isFinished(board, 'o' + 'x' - turn)) return -1;
    int& ret = cache[bijection(board)];
    if(ret != -2) return ret;
    int minValue = 2;
    for(int i = 0; i < MAX_N; i++) {
        for(int j = 0; j < MAX_N; j++)
            if(board[i][j] == '.') {
                board[i][j] = turn;
                minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
                board[i][j] = '.';
            }
    }
    if(minValue == 0 || minValue == 2) return ret = 0;
    else return ret = -minValue;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int C; cin >> C;
    while(C--) {
        for(int i = 0; i < 20000; i++)
            cache[i] = -2;
        char board[MAX_N][MAX_N];
        int dot = 0;
        for(int i = 0; i < MAX_N; i++) {
            cin >> board[i];
            for(int j = 0; j < MAX_N; j++)
                if(board[i][j] == '.') dot++;
        }

        char turn = 'o';
        if(dot % 2 == 1) turn = 'x';

        int result = canWin(board, turn);
        if(result == 1) cout << turn << '\n';
        else if(result == -1) cout << (char)('o' + 'x' - turn) << '\n';
        else cout << "TIE" << '\n';
    }
    return 0;
}