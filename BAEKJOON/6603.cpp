// 6603번 로또
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1) {
        int k; cin >> k;
        if(k == 0) break;

        vector <int> a(12);
        for(int i = 0; i < k; i++) {
           cin >> a[i];
        }

        int check[12];
        for(int i = 0; i < 6; i++) {
            check[i] = 0;
        }
        for(int i = 6; i < k; i++) {
            check[i] = 1;
        }

        sort(a.begin(), a.begin() + k);
        do {
            for(int i = 0; i < k; i++) {
                if(check[i] == 0)
                    cout << a[i] << " ";
            }      
            cout << '\n';
        } while (next_permutation(check, check + k));
        cout << '\n';
    }
    return 0;
}