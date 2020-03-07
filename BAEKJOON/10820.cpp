// 10820번 문자열 분석
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    // 소문자, 대문자, 숫자, 공백
    string str;
    while(getline(cin,str)) //EOF가 입력될 때 까지 입력받음
    {
        vector <int> ans(4);
        for(char ch : str)
        {
            if(ch >= 'a' && ch <= 'z')
                ans[0] += 1;
            else if(ch >= 'A' && ch <= 'Z')
                ans[1] += 1;
            else if(ch >= '0' && ch <= '9')
                ans[2] += 1;
            else if(ch == ' ')
                ans[3] += 1;
        }
        cout << ans[0] << " " << ans[1] << " ";
        cout << ans[2] << " " << ans[3] << '\n';
    }
    return 0;
}