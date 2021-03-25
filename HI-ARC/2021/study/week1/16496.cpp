// https://www.acmicpc.net/problem/16496
// 16496번 큰 수

// padding 설정을 잘못해서 틀렸다.

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define decimal cout << fixed; cout.precision(6);
using namespace std;

typedef long long ll;

int n;

bool cmp(pair<ll, string> a, pair<ll, string> b) {
    if(a.first == b.first) return (int)a.second.size() > (int)b.second.size();
    return a.first > b.first;
}

void solve() {
    cin >> n;
    vector<string> a(n);

    int maxSize = -1;
    for(string& el : a) {
        cin >> el;
        maxSize = max(maxSize, (int)el.size());
    }

    vector<pair<ll, string> > conv;
    for(int i = 0; i < n; i++) {
        string el = a[i];
        char padding = el[0];
        while(maxSize != (int)el.size() && el != "0") el += padding;
        conv.push_back(make_pair(stoll(el), a[i]));
    }

    sort(conv.begin(), conv.end(), cmp);

    if(conv[0].second == "0") {
        puts("0");
    } else {
        for(int i = 0; i < n; i++)
            cout << conv[i].second;
        cout << '\n';
    }
}

int main() {
    fastio;
    solve();
}

/*
2
14 143

2
78 7

2
54 5

2
56 5
*/