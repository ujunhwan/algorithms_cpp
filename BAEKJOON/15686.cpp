// 15686번 치킨 배달
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
queue <int> q;
int getDist (int x, int y) {
    return x > y ? x - y : y - x;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector <pair<int, int> > pos;
    vector <int> vec;
    int arr[51][51];
    int n, m; cin >> n >> m;    // m개만 남긴다
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                pos.push_back(make_pair(i, j));
                vec.push_back(0);
            }
        }
    }   // 0은 빈칸 1은 집 2는 치킨집
    int length = vec.size();
    for (int i = 0; i < m; i++) vec[length - 1 - i] = 2;
    int ans = INF; // 도시의 치킨 거리의 최솟값
    do {
        int chickenDist = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == 1) {
                    int tmp = INF;
                    for (int k = 0; k < length; k++) {
                        if (vec[k] == 0) continue;
                        int dist = getDist(pos[k].first, i) + getDist(pos[k].second, j);
                        tmp = min(dist, tmp);
                    }
                    chickenDist += tmp;
                }
            }
        }
        ans = min(chickenDist, ans);
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans << '\n';
    return 0;
}