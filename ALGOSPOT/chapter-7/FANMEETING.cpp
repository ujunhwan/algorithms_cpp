#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string member, fan;
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) 
            c[i+j] += a[i] * b[j];
    }
    return c;
}

void addTo (vector<int>&a, vector<int>&b, int k) {
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++) a[i + k] += b[i];
}

void subFrom (vector<int> &a, vector<int> &b) {
    a.resize(max(a.size(), b.size() + 1));
    for (int i = 0; i < b.size(); i++) a[i] -= b[i];
}

vector<int> karatsuba (const vector<int> &a , const vector<int> &b) {
    int an = a.size(), bn = b.size();
    if (an < bn) return karatsuba(b, a);
    if (an== 0 || bn == 0) return vector<int>();
    if (an <= 50) return multiply(a, b);
    
    int half = an / 2;
    vector<int> a0 (a.begin(), a.begin() + half);
    vector<int> a1 (a.begin() + half, a.end());
    vector<int> b0 (b.begin(), b.begin() + min<int>(half, bn));
    vector<int> b1 (b.begin() + min<int>(half, bn), b.end());

    vector<int> z2 = karatsuba (a1, b1);
    vector<int> z0 = karatsuba (a0, b0);
    addTo (a0, a1, 0);
    addTo (b0, b1, 0);

    vector<int> z1 = karatsuba (a0, b0);
    subFrom (z1, z0);
    subFrom (z1, z2);

    vector<int> ret;
    addTo (ret, z0, 0);
    addTo (ret, z1, half);
    addTo (ret, z2, half *2);
    return ret;
}

int solve(string member, string fan) {
    int mn = member.size(), fn = fan.size();
    vector<int> a(mn), b(fn);
    for (int i = 0; i < mn; i++) {
        a[mn - i - 1] = (member[i] == 'M');
    }
    for (int i = 0; i < fn; i++) {
        b[i] = (fan[i] == 'M');
    }
    int an = a.size(), bn = b.size();
    vector<int> ans = karatsuba(a, b);
    int ret = 0;
    for (int i = an - 1; i < bn; i++) {
        if (ans[i] == 0) ret += 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        cin >> member >> fan;
        cout << solve(member, fan) << '\n';
    }
}