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
        } else {
            if(matched == 0) begin += 1;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

vector<int>getPrefixSuffix(const string& s) {
    vector<int> ret, pi = getPartialMatch(s);
    int k = s.size();
    while(k > 0) {
        ret.push_back(k);
        k = pi[k - 1];
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string father, mother;
    cin >> father >> mother;
    string s = father + mother;
    vector<int>ans = getPrefixSuffix(s);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}