// 2529번 부등호
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<char> arr;
vector<string> ans;
bool check[10];
bool isRight(string num) {
    for(int i = 0; i < n; i ++) {
        if(num[i] < '0' || num[i] > '9') return false;
        if(arr[i] == '<')
            if(num[i] > num[i+1]) return false;
        if(arr[i] == '>')
            if(num[i] < num[i+1]) return false;
    }
    return true;
}

bool op(char x, char y, char op) {
    if(op == '<') return x < y ? true : false;
    if(op == '>') return x > y ? true : false;
    return false;
}

void func(int index, string num) {
    if(index == n + 1) {
        if(isRight(num)) {
            ans.push_back(num);
        }
        return;
    }
    for(int i = 0; i <= 9; i ++) {
        if(index == 0 || (op(num[index - 1] , i + '0', arr[index - 1]) == true && check[i] == false)) {
            check[i] = true;
            func(index + 1, num + to_string(i));
            check[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        char tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    func(0, "");
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] << '\n' << ans[0] << '\n';
    return 0;
}