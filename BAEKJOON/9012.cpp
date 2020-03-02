#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char str[50];
    int T;
    int cnt;

    cin >> T;
    for(int i=0;i<T;i++) 
    {
        cnt = 0;
        cin >> str;
        for(int j=0;j<strlen(str);j++)
        {
            if(cnt < 0)
            {
                cnt = 100;
            }
            if(str[j] == '(')
                cnt++;
            else if(str[j] == ')')
                cnt--;
        }
        if(cnt == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        
        str[0] = '\0';
    }
}