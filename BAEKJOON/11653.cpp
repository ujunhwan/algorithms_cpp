// 11653번 소인수분해
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    int factor = 2;
    while(N > 1)
    {
        if(N % factor == 0)
        {
            N /= factor;
            cout << factor << '\n';
        }
        else if(factor > 2) factor += 2;
        else factor += 1;
    }
}