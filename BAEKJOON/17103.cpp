// 17103번 골드바흐 파티션
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
static const int bufSize = 1 << 20;
bitset <bufSize> prime;
bool isPrime(int n)
{
    return prime.test(n) ? false : true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i=3;i<=1000;i+=2)
    {
        if(!prime.test(i))
            for(int j=i*i;j<=bufSize;j+=i)
                prime.set(j);
    }
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        int cnt = 0;
        for(int i=3;i<=N/2;i += 2)
        {
            int a = N - i;
            int b = i;
            if(isPrime(a) && isPrime(b))
                cnt += 1;
        }
        cout << cnt << '\n';
    }
}