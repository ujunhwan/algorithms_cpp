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
        if(s[matched] == s[begin + matched]) {
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

int palindromize(const string& haystack) {
    int m = haystack.size();
    string needle = haystack;
    reverse(needle.begin(), needle.end());
    int begin = 0, matched = 0;
    vector<int>pi = getPartialMatch(needle);
    while(begin < m) {
        if(matched < m && haystack[begin + matched] == needle[matched]) {
            matched += 1;
            if(begin + matched == m) 
                return matched;
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        string s; cin >> s;
        cout << s.size() * 2 - palindromize(s) << '\n';
    }
    return 0;
}