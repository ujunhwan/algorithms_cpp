#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int C, N, K, M;
int Li[51], Qi[51]; 
double T[51][51], c[51][5];

class SquareMatrix {
private:
    vector<vector<double>> v;
    int mSize; //matrix Size
public:
    SquareMatrix(int n) :mSize(n) {
        v.resize(mSize, vector<double>(mSize, 0));
    }

    ~SquareMatrix() {
        for (int i = 0; i < mSize; i++)
            v[i].clear();
        v.clear();
    }

    SquareMatrix identity(int n) { //단위행렬
        SquareMatrix result = SquareMatrix(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i == j)
                    result.v[i][j] = 1;
                else
                    result.v[i][j] = 0;
        return result;
    }

    SquareMatrix operator*(SquareMatrix &b) {
        SquareMatrix result = SquareMatrix(mSize);
        for (int i = 0; i < mSize; i++)
            for (int j = 0; j < mSize; j++)
                for (int k = 0; k < mSize; k++)
                    result.v[j][k] += v[j][i] * b.v[i][k];
        return result;
    }

    SquareMatrix pow(int k) {
            if (k == 0)
                    return identity(mSize);
            if (k % 2 == 1)
                    return pow(k - 1)**this;
            SquareMatrix half = pow(k / 2);
            return half*half;
    }

    double *operator[](int i) {
        return &v[i][0];
    }
};

void play() {
    SquareMatrix W(4 * N);
    for(int i = 0; i < 3 * N; i++)
        W[i][i + N] = 1.0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            W[3 * N + i][(4 - Li[j]) * N + j] = T[j][i];
        }
    }
    
    SquareMatrix Wk = W.pow(K);
    vector<double> ans(N);
    for(int song = 0; song < N; song++)
        for(int start = 0; start < Li[song]; start++)
            ans[song] += Wk[(3 - start) * N + song][3 * N];
    
    for(int i = 0; i < M; i++)
        cout << ans[Qi[i]] << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cout << fixed;
    cout.precision(8);
    cin >> C;
    while(C--) {
        cin >> N >> K >> M;
        for(int i = 0; i < N; i++)
            cin >> Li[i];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> T[i][j];
        for(int i = 0; i < M; i++)
            cin >> Qi[i];
        play();
    }
    return 0;
}