#include <iostream>
#include <stack>
#include <cstring>
#define STR_LENGTH 100000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string result;
    stack <char> left;
    stack <char> right;
    char cmd;
    char ch;
    int count;
    string inputStr;
    cin >> inputStr;
    for(int i=0;i<inputStr.length();i++)
        left.push(inputStr[i]);

    int T; cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> cmd;
        if(cmd == 'P') // 문자 추가
        {
            cin >> ch;
            left.push(ch);
        }
        else if(cmd == 'L') // 왼쪽으로
        {
            if(!(left.empty()))
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if(cmd == 'D') // 오른쪽으로
        {
            if(!(right.empty()))
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if(cmd == 'B') // 왼쪽에 있는 문자 삭제
        {
            if(!(left.empty()))
                left.pop();
        }
        else continue;
    }

    while(!(left.empty()))
    {
        right.push(left.top());
        left.pop();
    }
    
    while(!(right.empty()))
    {
        result += right.top();
        right.pop();
    }
    cout << result << '\n';
    return 0;
}