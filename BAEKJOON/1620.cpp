// 1620번 나는야 포켓몬 마스터 이다솜
#include <bits/stdc++.h>
using namespace std;
vector<string> numVector;
vector<pair<int, string> > strVector;
bool comp (const pair<int, string> &a, const pair<int, string> &b) {
    return a.second < b.second;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    numVector.push_back("");
    for (int i = 0; i < n; i++) {
        string name = "";
        cin >> name;
        numVector.push_back(name);
        strVector.push_back(make_pair(i+1, name));
    }
    sort(strVector.begin(), strVector.end(), comp);
    for (int i = 0; i < m; i++) {
        string cmd = "";
        cin >> cmd;
        if (cmd[0] >= '0' && cmd[0] <= '9') {
            int num = stoi(cmd);
            cout << numVector[num] << '\n';
        } else {
            int low = 0, high = n-1, mid = (low + high) / 2;
            while (low <= high) {
                mid = (low + high) / 2;
                if(strVector[mid].second == cmd) {
                    cout << strVector[mid].first << '\n';
                    break;
                } else if (strVector[mid].second < cmd) {
                    low = mid + 1;
                } else if (strVector[mid].second > cmd) {
                    high = mid - 1;
                }
            }
        }
    }
    return 0;
}
/*
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
*/