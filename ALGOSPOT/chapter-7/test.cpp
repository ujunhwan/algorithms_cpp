#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a = {3, 2, 1};
    for (int i = 0; i < a.size(); i++) {
        cout << i << " " << a[i] << '\n';
    }
    return 0;
}