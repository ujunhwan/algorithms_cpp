// 1676번 팩토리얼 0의 개수
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // 5의 개수가 정답
    int N; cin >> N;
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        int num = i;
        while(num % 5 == 0)
        {
            ans += 1;
            num /= 5;
        }
    }
    cout << ans << '\n';
    return 0;
}