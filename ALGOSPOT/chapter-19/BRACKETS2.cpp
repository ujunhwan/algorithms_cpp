#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool check(char c, char h) {
    if(c == ')') return h == '(';
    else if(c == ']') return h == '[';
    else if(c == '}') return h == '{';
    return false;
}

void bracket(const string str) {
    stack<char> st;
    for(int i = 0; i < str.size(); i++)
        if(!st.empty() && check(str[i], st.top())) st.pop();
        else st.push(str[i]);
    if(st.empty()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        string str; cin >> str;
        bracket(str);
    }
    return 0;
}