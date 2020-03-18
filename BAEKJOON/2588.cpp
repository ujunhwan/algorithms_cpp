// 2588번 곱셈
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int a,b; cin >> a >> b;
    int one,ten,hund;
    one = b % 10;
    ten = (b % 100 - one) / 10;
    hund = (b - (ten + one)) / 100;
    cout << a * one << '\n';
    cout << a * ten << '\n';
    cout << a * hund << '\n';
    cout << a * b << '\n';
}