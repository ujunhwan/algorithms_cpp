// 1003번 피보나치 함수
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    int a[40];
    int zero,one;
    int i;
    a[0] = 0;
    a[1] = 1;
    for(i=2;i<=40;i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    while(T--)
    {
        int N; cin >> N;
        if(N == 0)
        {
            zero = 1;
            one = 0;
        }
        else
        {
            zero = a[N-1];
            one = a[N];       
        }
        cout << zero << " " << one << '\n';
    }
}