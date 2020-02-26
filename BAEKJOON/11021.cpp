#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char comma;
    int num1;
    int num2;
    int T;

    cin >> T;
    for(int i=0;i<T;i++)
    {   
        cin >> num1 >> num2;
        cout << "Case #"<< i+1 << ": " << num1+num2 << '\n';
    }
}