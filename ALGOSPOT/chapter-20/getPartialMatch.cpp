#include <iostream>
#include <vector>
using namespace std;

int main() {
    //getPartialMatch
    string s; cin >> s;
    vector<int>pi(s.size(), 0);
    int begin = 1, matched = 0;
    while(begin + matched < s.size()) {
        cout << "begin = " << begin << " " << "matched = " << matched;
        cout << " pi index = " << begin + matched - 1 << '\n';
        if(s[begin + matched] == s[matched]) {
            matched += 1;
            pi[begin + matched - 1] = matched;
            cout << "pi[" << begin + matched - 1 << "] = " << matched << '\n';
        }
        else {
            if(matched == 0) {
                begin += 1;
                cout << "begin = " <<  begin << '\n';
            }
            else {
                begin += matched - pi[matched - 1];
                cout << "begin = " <<  begin << '\n';
                matched = pi[matched - 1];
            }
        }
    }
    for(int i = 0; i < pi.size(); i++)
                cout << pi[i] << " ";
            cout << '\n';
}