#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num1;
    int num2;
    while(num1 == 0 && num2 == 0)
    {
        cin >> num1 >> num2;  //EOF일 때까지 반복
        cout << num1+num2 << '\n';
    }
}