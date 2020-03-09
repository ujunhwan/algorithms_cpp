// 2609번 최대공약수와 최소공배수
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
    int A,B; cin >> A >> B;
    int gcd = GCD(A,B);
    cout << gcd << '\n'; 
    int lcm = A*B/gcd;
    cout << lcm << '\n';
    return 0;
}