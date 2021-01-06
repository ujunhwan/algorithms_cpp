#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstring>
using namespace std;

vector<int>child[100000 + 1];
int no2serial[100000 + 1];
int serial2no[100000 + 1];
int locInTrip[100000 + 1];
int depth[100000 + 1];
int nextNumber;

struct RMQ {
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 0, n - 1, 1);
    }

    int init(const vector<int>& array, int left, int right, int node)  {
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid ,node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left)
            return numeric_limits<int>::max();
        
        if(left <= nodeLeft && nodeRight <= right)
            return rangeMin[node];

        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node*2 + 1, mid + 1, nodeRight));
    }

    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};

void traverse(int here, int d, vector<int>&trip) {
    no2serial[here] = nextNumber;
    serial2no[nextNumber++] = here;
    locInTrip[here] = trip.size();
    depth[here] = d;
    trip.push_back(no2serial[here]);
    for(int i = 0; i < child[here].size(); i++) {
        traverse(child[here][i], d + 1, trip);
        trip.push_back(no2serial[here]);
    }
}

RMQ* precalc() {
    nextNumber = 0;
    vector<int>trip;
    traverse(0, 0, trip);
    RMQ* rmq = new RMQ(trip);
    return rmq;
}

int distance(int a, int b, RMQ* rmq) {
    int la = locInTrip[a], lb = locInTrip[b];
    if(la > lb) swap(la, lb);
    int lca = serial2no[rmq -> query(la, lb)];
    return depth[a] + depth[b] - 2 * depth[lca];
}

void initializer(int n) {
    for(int i = 0; i < n; i++) 
        child[i].clear();
    memset(no2serial, 0, sizeof(no2serial));
    memset(serial2no, 0, sizeof(serial2no));
    memset(locInTrip, 0, sizeof(locInTrip));
    memset(depth, 0, sizeof(depth));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        int n, q;
        cin >> n >> q;
        initializer(n);
        // child[p][q] -> p의 q번째 child node

        for(int i = 1; i < n; i++) {
            int c; cin >> c;
            child[c].push_back(i);
        }

        RMQ* rmq = precalc();
        for(int i = 0; i < q; i++) {
            int a, b; cin >> a >> b;
            cout << distance(a, b, rmq) << '\n';
        }
    }
    return 0;
}
/*
2 7
10 11
4 11
7 7
10 0
*/