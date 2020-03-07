// 1918번 후위 표기식
#include <iostream>
#include <stack>
using namespace std;
int GetOpPrec(char ch)
{
    if(ch == '*' || ch == '/')
        return 5;
    else if(ch == '+' || ch == '-')
        return 3;
    else if(ch == '(')
        return 1;
}
int whoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);
    if(op1Prec > op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //a+b*c -> abc*+
    //a*(b+c) -> abc+*
    //a+b*c -> (a+(b*c)) -> (a+bc*) -> abc*+

    stack <char> s;
    string ret;
    string str; cin >> str;  
    for(char ch : str)
    {
        // 0~25
        if(ch - 'A' < 26 && ch - 'A' >= 0)   // 알파벳, stack에 들어가지 않는다
            ret += ch;
        else if(ch == '(')
            s.push(ch);
        else if(ch == ')')
        {
            while(s.top() != '(')
            {
                ret += s.top();
                s.pop();
            }
            s.pop();
        }
        else // operator
        {
            if(ch == '*' || ch == '/')
            {
                while(!s.empty() && (s.top() == '*' || s.top() == '/'))
                {
                    ret += s.top();
                    s.pop();
                }
                s.push(ch);
            }
            else if(ch == '-' || ch == '+')
            {
                while(!s.empty() && s.top() != '(')
                {
                    ret += s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
    }
    while(!s.empty())
    {
        ret += s.top();
        s.pop();
    }
    cout << ret << '\n';
    return 0;
}