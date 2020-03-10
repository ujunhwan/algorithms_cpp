// 10872번 팩토리얼
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    int ans = 1;
    while(N)
    {
        ans *= N;
        N -= 1;
    }
    cout << ans << '\n';
    return 0;
}