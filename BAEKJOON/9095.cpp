// 9095번 1, 2, 3 더하기
#include <bits/stdc++.h>
using namespace std;
int op(int n)
{
    if(n < 1) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;
    return op(n-1) + op(n-2) + op(n-3);
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        cout << op(n) << '\n';
    }
}