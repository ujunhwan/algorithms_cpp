// 1929번 소수 구하기
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
static const int bufSize = 1 << 20;
bitset<bufSize> prime;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string ans = "";
    int M,N; cin >> M >> N;
    if(M <= 2 && N >= 2)
        ans += "2\n";
    for(int i=3;i<=N;i += 2) // 2의 배수는 어차피 상관x
    {
        if(!prime.test(i))
        {
            for(int j=i+i;j<=N;j += i)
                prime.set(j);
            if(M <= i && N >= i)
            {
                ans += to_string(i);
                ans += '\n';
            }
            if(ans.length() >= 1 << 19)
            {
                cout << ans << '\n';
                ans = "";
            }
        }
    }
    cout << ans << '\n';
    return 0;
}