// 1935번 후위 표기식2
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,j,k;
    int index = 0;
    int N; cin >> N;
    // ABC*+DE/-
    // B*C+A-D/E
    // 2*3+1-4/5
    string str; cin >> str;
    int num[26];
    for(i=0;i<N;i++)
        cin >> num[i];
    stack <double> s;
    for(char ch : str)
    {
        double d1,d2;
        if(ch == '*')
        {
            d2 = s.top();
            s.pop();
            d1 = s.top();
            s.pop();
            s.push(d1*d2);
        }
        else if(ch == '/')
        {
            d2 = s.top();
            s.pop();
            d1 = s.top();
            s.pop();
            s.push(d1/d2);
        }
        else if(ch == '+')
        {
            d2 = s.top();
            s.pop();
            d1 = s.top();
            s.pop();
            s.push(d1+d2);
        }
        else if(ch == '-')
        {
            d2 = s.top();
            s.pop();
            d1 = s.top();
            s.pop();
            s.push(d1-d2);
        }
        else
        {
            index = ch - 'A';
            s.push(num[index]);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';
}