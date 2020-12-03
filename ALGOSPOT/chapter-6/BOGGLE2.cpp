#include <cstdio>
#include <string>
using namespace std;

const int dx[8] = {0, 1};
const int dy[8] = {0, };
bool solve(int x, int y, int index, char str[], char map[][6]) {
    if(map[x][y] != str[index]) return false;
    if(strlen(str) - index == 1) return true;

    
}

int main() {
    int c; scanf("%d", &c);
    while(c--) {
        char map[6][6]; 
        for(int i = 0; i < 5; i++) scanf("%s", map[i]);
        printf("%c", map[2][3]);
        int s; scanf("%d", &s);
        char str[11][11];
        for(int i = 0; i < s; i++) {
            scanf("%s", str[i]);
        }

        for(int i = 0; i < s; i++) {
            if(solve(0, 0, 0, str[i], map) == true) {
                printf("TRUE\n");
            }
        }


    }
    return 0;
}

/*
1
URLPM
XPRET
GIAET
XTNZY
XOQRS
1
G
*/
