#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int C, N;
int c[2][1000];
int triangle[100][100];

int iterative() {
    int n = N;
    for(int x = 0; x < n; x++)
        c[(N - 1) % 2][x] = triangle[N - 1][x];
    for(int y = n - 2; y >= 0; y--) {
        for(int x = 0; x < y + 1; x++) 
            c[y%2][x] = max(c[(y+1)%2][x], c[(y+1)%2][x+1] + triangle[y][x]);
    }
    return c[0][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> C;
    while(C--) {
        cin >> N;
    }
    return 0;
}