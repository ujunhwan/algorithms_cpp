#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


int tc;
int main() {
    long long int num = (1 << 25);
    cout << num << '\n';
    vector<string> aa;
    aa.push_back("0");
    aa.push_back("1");
    aa.push_back("2");
    for(int i = 0; i < aa.size(); i++) {
        cout << aa[i] << '\n';
    }

    cout << aa.size() << '\n';

}