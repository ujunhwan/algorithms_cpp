// 1934번 최소공배수
#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
    if(b == 0)
        return a;
    else
        return GCD(b,a%b);
}
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int A,B; cin >> A >> B;
        int lcm = A*B/GCD(A,B);
        cout << lcm << '\n';
    }
    return 0;   
}