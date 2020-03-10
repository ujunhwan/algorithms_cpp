// 6588번 골드바흐의 추측
#include <iostream>
#include <bitset>
#include <string>
using namespace std;
static const int bufSize = 1 << 20;
bitset <bufSize> Prime;
inline bool isPrime(int n)
{
    if(Prime.test(n)) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for(int i=3;i<bufSize;i+=2)
    {
        if(!Prime.test(i))
        {
            if(i <= 1000)
                for(int j=i*i;j<bufSize;j+=i)
                    Prime.set(j);
        }
    }
    while(1)
    {
        int n,a,b; cin >> n;
        if(n == 0) break;
        for(int i=3;i<=n-3;i+=2)
        {
            b = n - i;
            if(isPrime(b) && isPrime(i))
            {
                a = i;
                cout << n << " = " << a << " + " << b << '\n';
                break;
            }
            if(i == n-3)
                cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }
}