// https://www.acmicpc.net/problem/1339
// 1339번 단어 수학

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

int n, alter[27], digit[27];

bool cmp(pii a, pii b) {
    return a.first > b.first;
}

void solve() {
    memset(alter, 0, sizeof(alter));
    memset(digit, 0, sizeof(digit));

    cin >> n;

    // calc digits
    string str[11];
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        for(int j = 0; j < str[i].size(); j++) {
            char now = str[i][j];
            digit[now - 'A'] += pow(10, str[i].size() - j - 1);
        }
    }

    // string value, string index
    vector<pii> a;
    for(int i = 0; i < 26; i++) a.emplace_back(digit[i], i);
    sort(a.begin(), a.end(), cmp);

    // set alter
    int cnt = 9;
    for(int i = 0; i < a.size(); i++) {
        int idx = a[i].second;
        alter[idx] = cnt < 0 ? 0 : cnt--;
    }

    // calc ans
    int ans = 0;
    for(int i = 0; i < n; i++) {
        string val = "";
        for(int j = 0; j < str[i].size(); j++)
            val += (alter[str[i][j] - 'A'] + '0');

        ans += stoi(val);
    }

    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
}