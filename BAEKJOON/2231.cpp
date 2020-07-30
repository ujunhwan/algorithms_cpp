// 2231번 분해합
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int ans = 0;
    int flag = -1;
    for (int i = 0 ; i < n; i++) {
        int sum = i;
        int j = i;
        while (j > 0) {
            int tmp = j % 10;
            j /= 10;
            sum += tmp;
        } 
        if (sum == n) {
            cout << i << '\n';
            flag = 1;
            break;
        }
    }
    if (flag == -1) cout << "0" << '\n';
    return 0;
}