// 1759번 암호 만들기
#include <bits/stdc++.h>
using namespace std;

bool check (string &str) {
    int length = str.length();
    int vwel = 0;
    for(int i = 0; i < length; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            vwel += 1;
    }
    return vwel >= 1 && (length - vwel) >= 2;
}

void func (int n, int index, string pwd, vector<char> &a) {
    int length = pwd.length();
    if(length == n) {
        if(check(pwd))
            cout << pwd << '\n';
        return;
    }

    if(index >= a.size()) return;
    func(n, index + 1, pwd + a[index], a);
    func(n, index + 1, pwd, a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l, c; cin >> l >> c;
    vector<char> a;
    for (int i = 0; i < c; i++) {
        char tmp; cin >> tmp;
        a.push_back(tmp);
    }  
    sort(a.begin(), a.end());
    func(l, 0, "", a);
    return 0;
}