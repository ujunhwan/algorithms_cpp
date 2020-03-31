// 1248번 맞춰봐
#include <bits/stdc++.h>
using namespace std;
int n; char s[10][10];
int k[10][10]; // 부분합
int a[10];
string ans = "";
bool isRight(int index){
    for(int i = 0; i <= index; i ++) {
        if(s[i][index] == '+' && k[i][index] <= 0) return false;
        if(s[i][index] == '-' && k[i][index] >= 0) return false;
        if(s[i][index] == '0' && k[i][index] != 0) return false;
    }
    return true;
}
void makeSum(int index) {
    for(int i = 0; i <= index; i ++) {
        k[i][index] = 0;
        for(int l = i; l <= index; l ++) {
            k[i][index] += a[l];
        }
    }
    return;
}
void go(int index) {
    if(ans.size() > 1) return;
    if(index == n) {
        if(isRight(n)) {
            string temp;
            for(int i = 0; i < n; i ++) {
                temp += to_string(a[i]);
                temp += " ";
            }
            ans = temp;
        }
        return;
    }
    if(index > n) return;
    if(s[index][index] == '+') {
        for(int i = 1; i <= 10; i ++) {
            a[index] = i;
            makeSum(index);
            if(isRight(index)) {
                go(index + 1);
            }
        }
    }
    if(s[index][index] == '-') {
        for(int i = -10; i < 0; i ++) {
            a[index] = i;
            makeSum(index);
            if(isRight(index)) {
                go(index + 1);
            }
        }
    }
    if(s[index][index] == '0') {
        a[index] = 0;
        makeSum(index);
        if(isRight(index)) {
            go(index + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i ++) 
    for(int j = i; j < n; j ++) 
        cin >> s[i][j];
    go(0);
    cout << ans[0] << '\n';
    return 0;
}