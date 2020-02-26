#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char comma;
    int num1;
    int num2;
    int n;

    cin >> n;
    for(int i=0;i<n;i++)
    {   
        cin >> num1 >> comma >> num2;
        cout << num1+num2 << '\n';
    }
}