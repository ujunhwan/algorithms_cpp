#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num1;
    int num2;

    while(1)
    {   
        cin >> num1 >> num2; 
        if(num1+num2 < 1)
            break;
        cout << num1+num2 << '\n';
    }
}