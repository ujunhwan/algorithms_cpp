#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>getPartialMatch(const string& s) {
    int m = s.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while(begin + matched < m) {
        if(s[begin + matched] == s[matched]) {
            matched += 1;
            pi[begin + matched - 1] = matched;
        }
        else {
            if(matched == 0) 
                begin += 1;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int kmp(const string& a, const string& b) {
    // b == needle
    vector<int> pi = getPartialMatch(b);
    int n = a.size(), m = b.size();
    int begin = 0, matched = 0;
    while(begin <= n - m) {
        if(matched < m && a[begin + matched] == b[matched]) {
            matched += 1;
            if(matched == m)
                return begin;
        }
        else {
            if(matched == 0)
                begin += 1;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return 0;
}

int solve(const vector<string> dial) {
    int ret = 0, m = dial[0].size();
    for(int i = 0; i < dial.size() - 1; i++) {
        if(i % 2 == 0)
            ret += kmp(dial[i + 1] + dial[i + 1], dial[i]);
        else
            ret += kmp(dial[i] + dial[i], dial[i + 1]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<string>dial;
        for(int i = 0; i <= n; i++) {
            string tmp; cin >> tmp;
            dial.push_back(tmp);
        }
        cout << solve(dial) << '\n';
    }
    return 0;
}