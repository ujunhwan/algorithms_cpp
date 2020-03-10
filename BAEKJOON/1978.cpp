// 1978번 소수 찾기
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++)
        if(n % i == 0) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int num;
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        cin >> num;
        if(isPrime(num))
            cnt += 1;
    }
    cout << cnt << '\n';
}