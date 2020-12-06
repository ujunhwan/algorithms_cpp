#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

queue<int> q;

int main() {
    for(int i = 0; i < 6; i++)
        q.push(i);
    q.pop();
    q.pop();
    for(int i = 0; i < 6; i++)
        cout << q.front() << '\n';
    multiset<int> s;
    int c = 5;
    while(c--) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i = 0; i < s.size(); i++) {
        cout << *s.rbegin() << '\n';    // big
        cout << *s.begin() << '\n';     // small
    }
    cout << "insert lower bound : " << '\n';
    cin >> c;
    cout << *s.lower_bound(c) << '\n';
}