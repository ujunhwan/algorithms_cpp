#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int C;
char cache[1 << 26];
vector<int> moves;

inline int cell(int y, int x) {
    return 1 << (y * 5 + x);
}

void precalc() {
    for(int y = 0; y < 4; y++)
        for(int x = 0; x < 4; x++) {
            vector<int> cells;
            for(int dy = 0; dy <= 1; dy++)
                for(int dx = 0; dx <= 1; dx++)
                    cells.push_back(cell(y + dy, x + dx));
            int square = 0;
            for(int i = 0; i < cells.size(); i++)
                square += cells[i];
            for(int j = 0; j < cells.size(); j++)
                moves.push_back(square - cells[j]);
    }

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 4; j++) {
            moves.push_back(cell(i, j) + cell(i, j + 1));
            moves.push_back(cell(j, i) + cell(j + 1, i));
    }
}

int bijection(string block[]) {
    int ret = 0, weight = 1;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++) {
            int val = 0;
            if(block[i][j] == '#') val = 1;
            ret += val * weight;
            weight *= 2;
    }
    return ret;
}

char canWin(int board) {
    char& ret = cache[board];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < moves.size(); i++)
        if((board & moves[i]) == 0)
            if(canWin(board | moves[i]) == 0) {
                ret = 1;
                break;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    precalc();
    cin >> C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        string board[5];
        for(int i = 0; i < 5; i++)
            cin >> board[i];
        canWin(bijection(board)) == 1 ? cout << "WINNING" << '\n' : cout << "LOSING" << '\n';
    }
    return 0;
}