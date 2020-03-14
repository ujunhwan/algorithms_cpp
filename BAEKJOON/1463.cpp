// 1463번 1로 만들기
#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int op(int n)
{
    if(n == 1) return 0;
    if(arr[n] > 0) return arr[n];
    arr[n] = op(n - 1) + 1; 
    if(n % 2 == 0)
    {
        int tmp = op(n / 2) + 1;
        if(arr[n] > tmp) arr[n] = tmp;
    }
    if(n % 3 == 0)
    {
        int tmp = op(n / 3) + 1;
        if(arr[n] > tmp) arr[n] = tmp;
    }
        return arr[n];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; cout << op(N) << '\n';
}