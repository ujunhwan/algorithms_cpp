// https://www.acmicpc.net/problem/1277
// 1277번 발전소 설치

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define precision(x) cout << fixed; cout.precision(x)
#define ll long long
#define pii pair<int, int>

using namespace std;

struct Pos {
    int x, y;
};

static const int INF = 0x3f3f3f3f;

int N, W;
double M;
Pos pos[1001];
vector<pair<int, double> > adj[1001];
int isConnected[1001][1001];

double calcDist(Pos a, Pos b) {
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

double dijkstra(int src) {
    vector<double> dist(1001, INF);
    priority_queue<pair<double, int> > pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;
        for(auto next : adj[here]) {
            int there = next.first;
            double nextCost = cost + next.second;
            if(dist[there] > nextCost) {
                dist[there] = nextCost;
                pq.push({-nextCost, there});
            }
        }
    }
    return dist[N];
}


void solve() {
    fill(&isConnected[0][0], &isConnected[1000][1001], -1);
    cin >> N >> W >> M;
    for(int i = 1; i <= N; i++) {
        cin >> pos[i].x >> pos[i].y;
    }

    // 현재 남아있는 전선
    for(int i = 0; i < W; i++) {
        int a, b;
        cin >> a >> b;
        isConnected[a][b] = true;
        isConnected[b][a] = true;
        adj[a].push_back({b, 0});
        adj[b].push_back({a, 0});
    }

    // 전선 연결
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            double d = calcDist(pos[i], pos[j]);
            if(d > M) continue;
            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }

    double ans = dijkstra(1);
    cout << (int)(ans * 1000) << '\n';
}

signed main() {
    fastio;
    solve();
}