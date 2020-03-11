// 17087번 숨바꼭질 6
#include <iostream>
#include <cmath>
using namespace std;
int GCD(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int N,S; cin >> N >> S;
    int A[N];
    for(int i=0;i<N;i++)
    {
        cin >> A[i];
        A[i] = abs(S - A[i]);
    }
    long long ans = A[0];
    for(int i=1;i<N;i++)
        ans = GCD(ans,A[i]);
    cout << ans;
    return 0;
}