#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int m, q, n;
string word[501];
int B[501];
double T[501][501], M[501][501];

void solve(int index, string target[], vector<string>& ans) {
    if(index == 0) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> q;
    for(int i = 0; i < m; i++) cin >> word[i];
    for(int i = 0; i < m; i++) cin >> B[i];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            cin >> T[i][j];
    for(int i = 0; i < q; i++) {
        cin >> n;
        string target[501];
        for(int j = 0; j < n; j++) {
            cin >> target[j];
        }
        vector<string> ans;
        solve(target, ans);
        for(int k = 0; k < ans.size(); k++)
            cout << ans[k] << " ";
        cout << '\n';
    }
}