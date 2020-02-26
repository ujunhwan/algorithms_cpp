#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num1;
    int num2;
    int n,i;

    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> num1 >> num2;
        cout << num1+num2 << '\n';
    }
}