#include <iostream>
#include <vector>
using namespace std;
void addTo (vector<int> & a, const vector<int> &b, int k) {

}

void subFrom (vector<int> &a, const vector<int> &b) {

}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
    // a * b = z2 * 10^n + z1 * 10^(n/2) + z0
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba (b, a);
    if (an == 0 || bn == 0) return vector<int>();
    int half = an / 2;
    vector<int> a0 (a.begin(), a.begin() + half);
    vector<int> a1 (a.begin() + half, a.end());
    vector<int> b0 (b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1 (b.begin() + min<int>(half, b.size()), b.end());

    vector<int> z2 = karatsuba (a1, b1);
    // z2 = a1 * b1
    vector<int> z0 = karatsuba (a0, b0);
    // z0 = a0 * b0
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    vector<int> z1 = karatsuba (a0, b0);
    subFrom (z1, z0); subFrom (z1, z2);
    // z1 = (a0 + a1) * (b0 + b1) - z0 - z1

    vector<int> ret;
    addTo (ret, z1, 0);
    addTo (ret, z1, half);
    addTo (ret, z2, half * 2);
    // a * b = z2 * 10^n + z1 * 10^(n/2) + z0
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}