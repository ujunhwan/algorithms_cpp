// 11726번 2xn 타일링
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int arr[n];   
    arr[0] = 0; arr[1] = 1; arr[2] = 2;
    for(int i=3;i<=n;i++)
        arr[i] = (arr[i-2] + arr[i-1]) % 10007;
    cout << arr[n] << '\n';
}