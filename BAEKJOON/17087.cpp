// 17087번 숨바꼭질 6
#include <iostream>
#include <cmath>
using namespace std;
int GCD(int a, int b)
{
    return b ? GCD(b,a%b) : a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N,S; cin >> N >> S;
    int A[N];
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
        A[i] = abs(S - A[i]);
        ans = GCD(ans,A[i]);
    }
    cout << ans;
    return 0;
}