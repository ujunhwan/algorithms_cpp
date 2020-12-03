#include <string>
#include <iostream>
using namespace std;
string reverseTree (string::iterator& it) {
    char head = *it;
    it++;
    if (head == 'b' || head == 'w')
        return string(1, head);
    string upperLeft = reverseTree(it);
    string upperRight = reverseTree(it);
    string lowerLeft = reverseTree(it);
    string lowerRight = reverseTree(it);
    return head + lowerLeft + lowerRight + upperLeft + upperRight;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        string quadtree; cin >> quadtree;
        string::iterator it = quadtree.begin();
        cout << reverseTree(it) << '\n';
    }
    return 0;
}