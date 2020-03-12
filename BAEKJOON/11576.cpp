// 11576번 Base Conversion
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int A, B; cin >> A >> B;
    int m; cin >> m;
    ll mid = 0;
    stack <int> s;
    for(int i=0;i<m;i++)
    {
        int num; cin >> num;
        num = num * pow(A,m-1-i);
        mid += num;
    }
    while(mid != 0)
    {
        s.push(mid % B);
        mid /= B;
    }
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << '\n';
}